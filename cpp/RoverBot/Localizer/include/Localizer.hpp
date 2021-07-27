#pragma once
#include <iostream>
#include <librealsense2/rs.hpp>

#include <iostream>
#include <memory>

#include "Types.hpp"
#include "NavPose2d_Pub.hpp"
#include "Position3d_Pub.hpp"
#include "Velocity3d_Pub.hpp"

class Localizer
{
    public:
        Localizer();
        ~Localizer();
        
        // TODO: refactor as virtual sensor interface
        void step();
        
    private:
        void setNavPose2d(NavPose2d& gNavPose) const;
        void setPose3d(Position3d& pose) const;
        void setVel3d(Velocity3d& vel) const;
        void setState3d(NavPose2d& gNavPose, VehicleState& gState) const; // not used

        std::unique_ptr<rs2::pipeline> m_pipe = nullptr;
        rs2_pose m_pose = {0};

        NavPose2d_Pub::NavPose2d_Pub m_NavPose2d_PubNode;
        Position3d_Pub::Position3d_Pub m_Position3d_PubNode;
        Velocity3d_Pub::Velocity3d_Pub m_Velocity3d_PubNode;
};