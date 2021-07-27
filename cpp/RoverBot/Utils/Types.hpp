#pragma once

#include <ostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

enum OpMode {
    Manual,
    ManualDisarmed,
    Waypoint,
    Reset,
    Continue,
    AutoDisarmed,
    Clear
};

inline std::string getModeString (OpMode mode)
{
    switch (mode)
    {
    case OpMode::Manual :
        return "Manual";
    case OpMode::ManualDisarmed :
        return "ManualDisarmed";
    case OpMode::Waypoint :
        return "Waypoint";
    case OpMode::Reset :
        return "Reset";
    case OpMode::Continue :
        return "Continue";
    case OpMode::AutoDisarmed :
        return "AutoDisarmed";
    case OpMode::Clear :
        return "Clear";
    
    default:
        return "Not Defined";
    }
}

inline OpMode getMode(std::string modeString)
{
    for (auto mode : {OpMode::Manual,
                      OpMode::ManualDisarmed,
                      OpMode::Waypoint,
                      OpMode::Reset,
                      OpMode::Continue,
                      OpMode::AutoDisarmed,
                      OpMode::Clear})
    {
        if (modeString == getModeString(mode))
            return mode;
    }
    return OpMode::ManualDisarmed;
}

enum OpCmd {
    Normal,
    SaveWaypoint,
    Shutdown
};

inline std::string getCmdString (OpCmd cmd)
{
    switch (cmd)
    {
    case OpCmd::Normal :
        return "Normal";
    case OpCmd::SaveWaypoint : 
        return "SaveWaypoint";
    case OpCmd::Shutdown : 
        return "Shutdown";
    default:
        return "Not Defined";
    }
}

inline OpCmd getCmd(std::string cmdString)
{
    for (auto cmd : {OpCmd::Normal,
                     OpCmd::SaveWaypoint,
                     OpCmd::Shutdown})
    {
        if (cmdString == getCmdString(cmd))
            return cmd;
    }
    return OpCmd::Shutdown;
}

// local pose determined by localization using local frame
struct NavPose2d
{
    float x;
    float y;
    float yaw;

    NavPose2d(float x_in, float y_in, float yaw_in) : x(x_in), y(y_in), yaw(yaw_in) {}
    NavPose2d() {}

    float operator-(const NavPose2d& rhs) {
        return fabs(x - rhs.x) + abs(y - rhs.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const NavPose2d& p)
    {
        os << std::setprecision(4) << "[x: " << p.x << " , y: " << p.y << " , yaw: " << p.yaw << "]";
        return os;
    }
};

struct VehicleState
{
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
    float roll;
    float pitch;
    float yaw;
    float vRoll;
    float vPitch;
    float vYaw;

    friend std::ostream& operator<<(std::ostream& os, const VehicleState& p)
    {
        os << std::setprecision(4) << "[x: " << p.x << ", y: " << p.y << ", z: " << p.z
                                   << ", vx: " << p.vx << ", vy: " << p.vy << ", vz: " << p.vz
                                   << ", roll: " << p.roll << ", pitch: " << p.pitch << ", yaw: " << p.yaw 
                                   << ", vRoll: " << p.roll << ", vPitch: " << p.vPitch << ", vYaw: " << p.vYaw << "]"
                                   << std::endl;
        return os;
    }
};

struct Route
{
    std::vector<NavPose2d> m_waypoints;
};

struct Power
{
    float boardVolt;
    float railVolt;
    float batVolt;
    float batCurrent;
};

struct Attitude
{
    float roll;
    float pitch;
    float yaw;
};

struct Position3d
{
    float x;
    float y;
    float z;
};

struct Velocity3d
{
    float x;
    float y;
    float z;
};
