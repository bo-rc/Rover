#include "Position3d_Sub.hpp"

void Position3d_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            pose.x = msg_.x();
            pose.y = msg_.y();
            pose.z = msg_.z();
        }
    }
}

void Position3d_Sub::Position3d_Sub::update(Position3d &pose)
{
    pose = listener_.pose;
}