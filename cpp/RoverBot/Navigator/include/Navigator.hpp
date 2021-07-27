#pragma once
#include <iostream>
#include <vector>
#include "PIDCtrl.hpp"
#include "Types.hpp"
#include "NavPose2d_Sub.hpp"
#include "OpCmd_Sub.hpp"
#include "OpMode_Sub.hpp"
#include "ManCmd_Sub.hpp"
#include "ActCmd_Pub.hpp"

class Navigator
{
    public:
        Navigator(std::vector<NavPose2d> route, float tolerance);
        
        void step();

    private:
        void autoNav();
        float getSteering(const NavPose2d& currPose, const NavPose2d& tgtPose);
        void saveWaypoint();

        bool checkTgtIndex();
        bool checkDistance();
        std::vector<NavPose2d> m_route;
        std::vector<bool> m_visited;
        size_t m_currIndex = 0;
        float m_tolerance = 0.1; // meter
        float m_cruiseThrottle = 0.4; // 

        PIDCtrl m_ctrl;
        OpMode m_mode;
        OpCmd m_cmd;

        int m_displayCounter = 0;
        bool m_resetToggle = false;

        NavPose2d_Sub::NavPose2d_Sub m_NavPose2d_SubNode;
        NavPose2d m_currPose;
        OpCmd_Sub::OpCmd_Sub m_OpCmd_SubNode;
        OpCmd m_currCmd;
        OpMode_Sub::OpMode_Sub m_OpMode_SubNode;
        OpMode m_currMode;
        ManCmd_Sub::ManCmd_Sub m_ManCmd_SubNode;
        float m_currManSteer;
        float m_currManThrottle;
        ActCmd_Pub::ActCmd_Pub m_ActCmd_PubNode;

        void update_();
};