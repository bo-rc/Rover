#include <iostream>
#include "BatteryMonitor.hpp"

#define ADC_SYSFS_PATH "/sys/kernel/rcio/adc"

BatteryMonitor::BatteryMonitor()
{
    initialize();
}

BatteryMonitor::~BatteryMonitor()
{
}

void BatteryMonitor::initialize()
{
    for (size_t i = 0; i < ARRAY_SIZE(channels); i++)
    {
        channels[i] = open_channel(i);
        if (channels[i] < 0)
        {
            perror("open");
        }
    }
}

int BatteryMonitor::open_channel(int channel)
{
    char *channel_path;
    asprintf(&channel_path, "%s/ch%d", ADC_SYSFS_PATH, channel);

    int fd = ::open(channel_path, O_RDONLY);

    free(channel_path);

    return fd;
}

int BatteryMonitor::get_channel_count(void)
{
    return CHANNEL_COUNT;
}

int BatteryMonitor::read(int ch)
{
    if (ch > ARRAY_SIZE(channels))
    {
        fprintf(stderr, "Channel number too large\n");
        return -1;
    }
    char buffer[10];

    if (::pread(channels[ch], buffer, ARRAY_SIZE(buffer), 0) < 0)
    {
        perror("pread");
    }

    return atoi(buffer);
}


void BatteryMonitor::step()
{
    float boardVolt = float(read(0)) / 1000.f;
    float railVolt = float(read(1)) / 1000.f;
    float batVolt = float(read(2)) * 14.23;
    float batCurrent = float(read(3)) * 2.0;

    m_Power_PubNode.update(boardVolt, railVolt, batVolt, batCurrent);
}
