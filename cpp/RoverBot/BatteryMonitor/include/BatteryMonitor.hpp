#pragma once

#include "Power_Pub.hpp"

#include "navioutil.hpp"
#include "Types.hpp"
#define CHANNEL_COUNT 6
class BatteryMonitor
{

public:
    
    BatteryMonitor();
    ~BatteryMonitor();
    void step();

private:

    void initialize();
    int get_channel_count(void);
    int read(int ch);
    int open_channel(int ch);

    int channels[CHANNEL_COUNT];

    Power_Pub::Power_Pub m_Power_PubNode;
};