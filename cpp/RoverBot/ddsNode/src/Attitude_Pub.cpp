#include "Attitude_Pub.hpp"

bool Attitude_Pub::Attitude_Pub::publish(Attitude att)
{
    if (listener_.matched_ > 0)
    {
        msg_.roll(att.roll);
        msg_.pitch(att.pitch);
        msg_.yaw(att.yaw);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

void Attitude_Pub::Attitude_Pub::update(Attitude att)
{
    publish(att);
}