#include "NavPose2d_Sub.hpp"

void NavPose2d_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            pose.x = msg_.x();
            pose.y = msg_.y();
            pose.yaw = msg_.yaw();
        }
    }
}

void NavPose2d_Sub::NavPose2d_Sub::update(NavPose2d &pose)
{
    pose = listener_.pose;
}