#pragma once

#include <cstddef>

#include "Configurations.hpp"
#include "ManCmd_Pub.hpp"
#include "OpCmd_Pub.hpp"
#include "OpMode_Pub.hpp"
#include "Types.hpp"

class RCinput
{
public:
    RCinput() = delete;
    RCinput(Configurations config);
    ~RCinput();

    void step();
    int read(int ch);

private:
    int open_channel(int ch);
    void initialize();
    float normalize(int pwm, int ch);
    static const size_t CHANNEL_COUNT = 14;
    int channels[CHANNEL_COUNT];
    Configurations m_config;
    int m_cmdState = 1;

    ManCmd_Pub::ManCmd_Pub m_ManCmd_PubNode;
    OpCmd_Pub::OpCmd_Pub m_OpCmd_PubNode;
    OpMode_Pub::OpMode_Pub m_OpMode_PubNode;
};
