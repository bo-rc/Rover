#include <math.h>
#include <eigen3/Eigen/Dense>

#include "Localizer.hpp"


Localizer::Localizer() : m_pose{0}
{
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_POSE, RS2_FORMAT_6DOF);

    m_pipe = std::make_unique<rs2::pipeline>();
    m_pipe->start(cfg);
}

Localizer::~Localizer()
{
    m_pipe->stop();
    m_pose = {0};
    m_pipe = nullptr;
}

void Localizer::step()
{
    auto frames = m_pipe->wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    m_pose = f.as<rs2::pose_frame>().get_pose_data();

    NavPose2d navPose;
    setNavPose2d(navPose);
    m_NavPose2d_PubNode.update(navPose);

    Position3d pose3d;
    setPose3d(pose3d);
    m_Position3d_PubNode.update(pose3d);

    Velocity3d vel3d;
    setVel3d(vel3d);
    m_Velocity3d_PubNode.update(vel3d);
}

void Localizer::setNavPose2d(NavPose2d& navPose) const
{
    Eigen::Quaternion q(m_pose.rotation.w, m_pose.rotation.x, m_pose.rotation.y, m_pose.rotation.z);

    auto rot = q.toRotationMatrix().eulerAngles(0,1,2);

    // TODO: use tf to transform camera frame -> vehicle frame using camera calib
    // here we use NED
    navPose = {m_pose.translation.x, - m_pose.translation.z, -rot[2]};
}


void Localizer::setPose3d(Position3d& pose) const
{
    // TODO: use tf to transform camera frame -> vehicle frame using camera calib
    // here we use NED
    pose = {m_pose.translation.x, - m_pose.translation.z, -m_pose.translation.y};
}

void Localizer::setVel3d(Velocity3d& vel) const
{
    // TODO: use tf to transform camera frame -> vehicle frame using camera calib
    // here we use NED
    vel = {m_pose.velocity.x, - m_pose.velocity.z, -m_pose.velocity.y};
}

// not used
void Localizer::setState3d(NavPose2d& gNavPose, VehicleState& gState) const
{
    Eigen::Quaternion q(m_pose.rotation.w, m_pose.rotation.x, m_pose.rotation.y, m_pose.rotation.z);

    auto rot = q.toRotationMatrix().eulerAngles(0,1,2);

    // TODO: use tf to transform camera frame -> vehicle frame using camera calib
    // here we use NED
    gNavPose = {m_pose.translation.x, - m_pose.translation.z, -rot[2]};
    gState   = {m_pose.translation.x, - m_pose.translation.z, -m_pose.translation.y, 
                m_pose.velocity.x, - m_pose.velocity.z, -m_pose.velocity.y,
                0, 0, rot[2],
                0, 0, -m_pose.angular_velocity.z};
}