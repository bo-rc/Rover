#include "OpCmd_Pub.hpp"

//!Send a publication
bool OpCmd_Pub::OpCmd_Pub::publish(std::string cmd)
{
    if (listener_.matched_ > 0)
    {
        msg_.OpCmd(cmd);
        writer_->write(&msg_);
        return true;
    }
    return false;
}

//!Run the Subscriber
void OpCmd_Pub::OpCmd_Pub::update(std::string cmd)
{
    publish(cmd);
}