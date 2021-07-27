#include <algorithm>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <err.h>

#include "RCinput.hpp"
#include "navioutil.hpp"

#define RCIN_SYSFS_PATH "/sys/kernel/rcio/rcin"

constexpr float pwmMax = 2000;
constexpr float pwmMin = 1000;
constexpr float nPwmMax = 1.0;
constexpr float nPwmMin = -1.0;

RCinput::RCinput(Configurations config) : m_config(config)
{
    initialize();
}

RCinput::~RCinput()
{
}

void RCinput::initialize()
{
    for (size_t i = 0; i < ARRAY_SIZE(channels); i++) {
        channels[i] = open_channel(i);
        if (channels[i] < 0) {
            perror("open");
        }
    }
}

float RCinput::normalize(int pwm, int ch)
{
    // TODO: use per-channel calibration to normalize channels
    (void)ch;

    float ratio = (float(pwm) - pwmMin) / (pwmMax - pwmMin);
    float nPwm = ratio * (nPwmMax - nPwmMin) + nPwmMin;

    return std::clamp(nPwm, nPwmMin, nPwmMax);
}

void RCinput::step()
{
   // CMD
    OpCmd gCmd {};

    // Shutdown CMD
    int currCmdShutdown = read(m_config.m_channelMap.shutdown);
    float nCurrCmdShutdown = normalize(currCmdShutdown, m_config.m_channelMap.shutdown);

    int currCmd = read(m_config.m_channelMap.cmd);
    float nCurrCmd = normalize(currCmd, m_config.m_channelMap.cmd);
    
    if (nCurrCmdShutdown < 0.0)
    {
        gCmd = OpCmd::Shutdown;
    }
    else if (nCurrCmd < 0.)
    {
        gCmd = OpCmd::Normal;
    }
    else
    {
        gCmd = OpCmd::SaveWaypoint;
    }

    m_OpCmd_PubNode.update(getCmdString(gCmd));

    // Mode 
    OpMode gMode {};
    int currMode = read(m_config.m_channelMap.mode);
    float nCurrMode = normalize(currMode, m_config.m_channelMap.mode);

    if (nCurrMode < -0.5) {
        gMode = OpMode::Manual;
    }
    else if (nCurrMode > -0.25 && nCurrMode < 0.25 )
    {
        gMode = OpMode::Waypoint;
    }
    else
    {
        gMode = OpMode::Reset;
    }    
    
    int currModeAux = read(m_config.m_channelMap.mode_aux);
    float nCurrModeAux = normalize(currModeAux, m_config.m_channelMap.mode_aux);
    
    if (nCurrModeAux < -0.5)
    {
        // inactive;
    }
    else if (nCurrModeAux > -0.25 && nCurrModeAux < 0.25 )
    {
        gMode = OpMode::Continue;
    }
    else
    {
        gMode = OpMode::Clear;
    }

    if (gCmd == OpCmd::Shutdown)
    {
        switch (gMode)
        {
        case OpMode::Manual :
        case OpMode::Clear :
            gMode = OpMode::ManualDisarmed;
            break;
        case OpMode::Waypoint :
        case OpMode::Reset :
        case OpMode::Continue :
            gMode = OpMode::AutoDisarmed;
            break;
        default:
            break;
        }
    }

    m_OpMode_PubNode.update(getModeString(gMode));
    
    // Steer and Throttle
    int currSteer = read(m_config.m_channelMap.steer);
    float nCurrSteer = normalize(currSteer, m_config.m_channelMap.steer);

    int currThrottle = read(m_config.m_channelMap.throttle);
    float ncurrThrottle = normalize(currThrottle, m_config.m_channelMap.throttle);

    m_ManCmd_PubNode.update(nCurrSteer, ncurrThrottle);
}

int RCinput::read(int ch)
{
    if (ch > ARRAY_SIZE(channels) )
	{	
        fprintf(stderr,"Channel number too large\n");
        return -1;
	}

    char buffer[10];

    if (::pread(channels[ch], buffer, ARRAY_SIZE(buffer), 0) < 0) {
        perror("pread");
    }

    return atoi(buffer);
}

int RCinput::open_channel(int channel)
{
    char *channel_path;
    if (asprintf(&channel_path, "%s/ch%d", RCIN_SYSFS_PATH, channel) == -1) {
        err(1, "channel: %d\n", channel);
    }

    int fd = ::open(channel_path, O_RDONLY);

    free(channel_path);

    return fd;
}

