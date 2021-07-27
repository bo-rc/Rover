#include "Power_Sub.hpp"

void Power_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            power.boardVolt = msg_.boardVolt();
            power.railVolt = msg_.railVolt();
            power.batVolt = msg_.batVolt();
            power.batCurrent = msg_.batCurrent();
        }
    }
}

void Power_Sub::Power_Sub::update(Power &power)
{
    power = listener_.power;
}