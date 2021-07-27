#include "ManCmd_Pub.hpp"

bool ManCmd_Pub::ManCmd_Pub::publish(float steer, float throttle)
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

void ManCmd_Pub::ManCmd_Pub::update(float steer, float throttle)
{
    publish(steer, throttle);
}