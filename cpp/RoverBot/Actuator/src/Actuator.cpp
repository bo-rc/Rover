#include <chrono>
#include <thread>
#include <iostream>
#include "Actuator.hpp"
#include "navioutil.hpp"

Actuator::Actuator(Configurations config) : m_config(config)
{
    for (int i = 0; i < 4; ++i)
    {
        init(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        set_period(i, 50);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        enable(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

bool Actuator::init(unsigned int channel)
{
    int err;
    err = write_file("/sys/class/pwm/pwmchip0/export", "%u", channel);
    if (err >= 0 || err == -EBUSY)
    {
        return true;
    }
    else 
    {
        printf("Can't init channel %u\n", channel);
        return false;
    }
    return true;
}

bool Actuator::enable(unsigned int channel)
{
    char path[60] = "/sys/class/pwm/pwmchip0";
    char path_ch[20];
    sprintf(path_ch, "/pwm%u/enable", channel);
    strcat(path, path_ch);
    
    if (write_file(path, "1") < 0)
    {
        printf("Can't enable channel %u\n", channel);
        return false;
    }
    return true;
}

bool Actuator::set_period(unsigned int channel, unsigned int freq)
{
    int period_ns;
    char path[60] = "/sys/class/pwm/pwmchip0";
    char path_ch[20];
    sprintf(path_ch, "/pwm%u/period", channel);
    strcat(path, path_ch);

    period_ns = 1e9 / freq;
    if (write_file(path, "%u", period_ns) < 0)
    {
        printf("Can't set period to channel %u\n", channel);
        return false;
    }
    return true;
}

bool Actuator::set_duty_cycle(unsigned int channel, float period)
{
    int period_ns;
    char path[60] = "/sys/class/pwm/pwmchip0";
    char path_ch[20];
    sprintf(path_ch, "/pwm%u/duty_cycle", channel);
    strcat(path, path_ch);

    period_ns = period * 1e6;
    // std::cout << channel << ":" << period_ns / 1000. << " us" << std::endl;
    if (write_file(path, "%u", period_ns) < 0)
    {
        printf("Can't set duty cycle to channel %u\n", channel);
        return false;
    }
    return true;
}

void Actuator::step()
{
    m_ActCmd_SubNode.update(m_currSteer, m_currThrottle);
    
    float sRatio = (m_currSteer + m_config.m_channelMap.steer_trim - (-1.)) / 2.0;
     
    float cmdSteer = sRatio * 1.0 + 1.0; 
    
    set_duty_cycle(m_config.m_channelMap.steer_output, cmdSteer);

    float tRatio = (m_currThrottle - (-1.)) / 2.0;
     
    float cmdThrottle = tRatio * 1.0 + 1.0; 
    
    set_duty_cycle(m_config.m_channelMap.throttle_output, cmdThrottle);
}