#include "ActCmd_Pub.hpp"

bool ActCmd_Pub::ActCmd_Pub::publish(float steer, float throttle)
{
    if (listener_.matched_ > 0)
    {
        msg_.steer(steer);
        msg_.throttle(throttle);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

void ActCmd_Pub::ActCmd_Pub::update(float steer, float throttle)
{
    publish(steer, throttle);
}