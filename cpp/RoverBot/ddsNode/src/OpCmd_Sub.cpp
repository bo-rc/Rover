#include "OpCmd_Sub.hpp"

void OpCmd_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            auto m = msg_.OpCmd();
            cmd = getCmd(m);
        }
    }
}

void OpCmd_Sub::OpCmd_Sub::update(OpCmd &cmd)
{
    cmd = listener_.cmd;
}