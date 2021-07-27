#include "Velocity3d_Pub.hpp"

bool Velocity3d_Pub::Velocity3d_Pub::publish(Velocity3d vel)
{
    if (listener_.matched_ > 0)
    {
        msg_.x(vel.x);
        msg_.y(vel.y);
        msg_.z(vel.z);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

void Velocity3d_Pub::Velocity3d_Pub::update(Velocity3d vel)
{
    publish(vel);
}