#define _USE_MATH_DEFINES
#include "Navigator.hpp"
#include <iterator>
#include <algorithm>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <iomanip>

Navigator::Navigator(std::vector<NavPose2d> route, float tolerance) : m_route{route}, m_tolerance{tolerance}
{
    m_visited.resize(m_route.size(), false);
}

void Navigator::update_()
{
    m_NavPose2d_SubNode.update(m_currPose);
    m_OpCmd_SubNode.update(m_currCmd);
    m_OpMode_SubNode.update(m_currMode);
    m_ManCmd_SubNode.update(m_currManSteer, m_currManThrottle);
}

void Navigator::step()
{
    // m_currPose = gNavPose;
    update_();

    if (m_currCmd == OpCmd::Normal)
    {
        m_cmd = m_currCmd;
    }

    if (m_currCmd != m_cmd)
    {
        if (m_currCmd == OpCmd::SaveWaypoint)
        {
            m_cmd = m_currCmd;
            saveWaypoint();
        }
    }

    switch (m_currMode) {
        case OpMode::Manual : 
            m_resetToggle = false;
            m_ActCmd_PubNode.update(m_currManSteer, m_currManThrottle);
            break;
        case OpMode::Waypoint :
            m_resetToggle = false;
            autoNav();
            break;
        case OpMode::Reset :

            if (not m_resetToggle and m_route.size() > 0)
            {
                m_currIndex = 0;
                std::fill(m_visited.begin(), m_visited.end(), false);

                std::cout << "restart waypoints ->" << std::endl;
                m_resetToggle = true;    
            }

            autoNav();
            break;
        case OpMode::Continue :
            if (not checkTgtIndex() and m_route.size() > 0)
            {
                m_currIndex = 0;
                std::fill(m_visited.begin(), m_visited.end(), false);
                std::cout << "restart waypoints ->" << std::endl;
            }
            
            autoNav();
            break;
        case OpMode::Clear :
            if (m_route.size() > 0)
            {
                m_currIndex = 0;
                m_route.clear();
                m_visited.clear();
                std::cout << "cleared waypoints ->" << std::endl;
            }

            m_ActCmd_PubNode.update(m_currManSteer, m_currManThrottle);
            break;
        case OpMode::ManualDisarmed :
        case OpMode::AutoDisarmed :
            m_ActCmd_PubNode.update(m_currManSteer, 0);
            break;
    }
}

void Navigator::saveWaypoint()
{
    m_route.push_back(m_currPose);
    m_visited.push_back(false);

    std::cout << " Saved current waypoint: " << m_currPose << std::endl;
    std::cout << "   Total wpts: " << m_route.size() << ", finished: " 
    << std::count(m_visited.cbegin(), m_visited.cend(), true) << std::endl;
}

void Navigator::autoNav()
{
    bool hasTgt = checkTgtIndex();
    if (hasTgt)
    {
        bool arrived = checkDistance();

        if (!arrived)
        {
            auto steer = getSteering(m_currPose, m_route[m_currIndex]);
            auto throttle = m_cruiseThrottle * (1.05 + m_currManThrottle);
            m_ActCmd_PubNode.update(steer, throttle);
        }
        else
        {
            m_ActCmd_PubNode.update(0., 0.);
        }
        
    }
}

float Navigator::getSteering(const NavPose2d& currPose, const NavPose2d& tgtPose)
{
    return m_ctrl.compute(currPose, tgtPose);
}

bool Navigator::checkTgtIndex()
{
    auto Itr = std::find(m_visited.cbegin(), m_visited.cend(), false);
    if (Itr == m_visited.cend())
    {
        return false;
    }

    m_currIndex = std::distance(m_visited.cbegin(), Itr);

    return true;
}

bool Navigator::checkDistance()
{
    float distance = m_route[m_currIndex] - m_currPose;
    if (++m_displayCounter > 20)
    {
        std::cout << "distance to target <" << m_currIndex << ">: " << distance << " m" << std::endl;
        m_displayCounter = 0;
    }
    
    if (distance < m_tolerance)
    {
        std::cout << std::setprecision(4) << "reached: " << m_currIndex << std::endl;
        m_visited[m_currIndex] = true;
        return true;
    }
    else
    {
        return false;
    }
    
}