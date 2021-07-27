#include "Attitude_Sub.hpp"

void Attitude_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            att.roll = msg_.roll();
            att.pitch = msg_.pitch();
            att.yaw = msg_.yaw();
        }
    }
}

void Attitude_Sub::Attitude_Sub::update(Attitude &att)
{
    att = listener_.att;
}