#include "Position3d_Pub.hpp"

bool Position3d_Pub::Position3d_Pub::publish(Position3d pose)
{
    if (listener_.matched_ > 0)
    {
        msg_.x(pose.x);
        msg_.y(pose.y);
        msg_.z(pose.z);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

void Position3d_Pub::Position3d_Pub::update(Position3d pose)
{
    publish(pose);
}