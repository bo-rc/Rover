#include "ManCmd_Sub.hpp"

void ManCmd_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            steer_ = msg_.steer();
            throttle_ = msg_.throttle();
        }
    }
}

void ManCmd_Sub::ManCmd_Sub::update(float &steer, float &throttle)
{
    steer = listener_.steer_;
    throttle = listener_.throttle_;
}