#include "Power_Pub.hpp"

//!Send a publication
bool Power_Pub::Power_Pub::publish(float boardVolt, float railVolt, float batVolt, float batCurrent)
{
    if (listener_.matched_ > 0)
    {
        msg_.boardVolt(boardVolt);
        msg_.railVolt(railVolt);
        msg_.batVolt(batVolt);
        msg_.batCurrent(batCurrent);

        writer_->write(&msg_);
        return true;
    }
    return false;
}

//!Run the Subscriber
void Power_Pub::Power_Pub::update(float boardVolt, float railVolt, float batVolt, float batCurrent)
{
    publish(boardVolt, railVolt, batVolt, batCurrent);
}