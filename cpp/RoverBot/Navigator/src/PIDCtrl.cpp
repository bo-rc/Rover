#include <algorithm>
#include <numeric>
#include "PIDCtrl.hpp"
#include "Eigen/Dense"

PIDCtrl::PIDCtrl(float p, float i, float d) : m_P{p}, m_I{i}, m_D{d}
{
    // nothing to do;
}

PIDCtrl::PIDCtrl()
{
    // nothing to do;
}

PIDCtrl::~PIDCtrl()
{
    // nothing to do;
}

float PIDCtrl::compute(float curr, float tgt)
{
    float e = curr - tgt;
    return compute(e);
}

float PIDCtrl::compute(NavPose2d currPose, NavPose2d tgtPose)
{
    Eigen::Vector2f heading(std::cos(currPose.yaw), std::sin(currPose.yaw));
    Eigen::Vector2f tgtHeading(tgtPose.x - currPose.x, tgtPose.y - currPose.y);
    Eigen::Vector2f nHeading = heading.normalized();
    Eigen::Vector2f nTgtHeading = tgtHeading.normalized();

    auto dot = nHeading[0]*nTgtHeading[0] + nHeading[1]*nTgtHeading[1]; // ~ cos(theta)
    auto det = nHeading[0]*nTgtHeading[1] - nHeading[1]*nTgtHeading[0]; // ~ sin(theta)

    auto angle = atan2(det, dot); // arctan(*)

    // std::cout << "angle: " << angle << std::endl;

    return compute(angle);
}

float PIDCtrl::compute(float error)
{
    m_error.push_back(error);

    if (m_error.size() > m_maxSize)
    {
        m_error.pop_front();
    }

    float cmd = -m_P * error - m_I * std::accumulate(m_error.cbegin(), m_error.cend(), 0.0) / m_error.size() + m_D * error;

    // normalized pwm range: [-1.0, 1.0]
    float cmdSend = std::clamp(cmd, -1.0f, 1.0f);
    // std::cout << "cmdSend = " << cmdSend << std::endl;

    return cmdSend;
}