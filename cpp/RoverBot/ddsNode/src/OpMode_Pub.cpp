#include "OpMode_Pub.hpp"

//!Send a publication
bool OpMode_Pub::OpMode_Pub::publish(std::string mode)
{
    if (listener_.matched_ > 0)
    {
        msg_.OpMode(mode);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

//!Run the Subscriber
void OpMode_Pub::OpMode_Pub::update(std::string mode)
{
    publish(mode);
}