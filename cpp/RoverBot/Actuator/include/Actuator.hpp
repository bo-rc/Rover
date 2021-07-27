#pragma once

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#include "Configurations.hpp"
#include "ActCmd_Sub.hpp"

class Actuator
{
public:
    Actuator() = delete;
    Actuator(Configurations config);

    void step();

private:
    
    bool init(unsigned int channel);
    bool enable(unsigned int channel);
    bool set_period(unsigned int channel, unsigned int freq);
    bool set_duty_cycle(unsigned int channel, float period);

    ActCmd_Sub::ActCmd_Sub m_ActCmd_SubNode;

    Configurations m_config;
    float m_currSteer = 0.f;
    float m_currThrottle = 0.f;
};
