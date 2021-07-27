#include "NavPose2d_Pub.hpp"

bool NavPose2d_Pub::NavPose2d_Pub::publish(NavPose2d pose)
{
    if (listener_.matched_ > 0)
    {
        msg_.x(pose.x);
        msg_.y(pose.y);
        msg_.yaw(pose.yaw);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

void NavPose2d_Pub::NavPose2d_Pub::update(NavPose2d pose)
{
    publish(pose);
}