#include "Velocity3d_Sub.hpp"

void Velocity3d_Sub::Listener::on_data_available(DataReader *reader)
{
    SampleInfo info;
    if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE)
        {
            vel.x = msg_.x();
            vel.y = msg_.y();
            vel.z = msg_.z();
        }
    }
}

void Velocity3d_Sub::Velocity3d_Sub::update(Velocity3d &vel)
{
    vel = listener_.vel;
}