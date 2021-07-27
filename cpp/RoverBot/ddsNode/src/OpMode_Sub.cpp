#include "OpMode_Sub.hpp"

void OpMode_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            auto m = msg_.OpMode();
            mode = getMode(m);
        }
    }
}

void OpMode_Sub::OpMode_Sub::update(OpMode &mode)
{
    mode = listener_.mode;
}