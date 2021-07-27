#pragma once

#include <ostream>
#include <fstream>
#include <iostream>
#include "json.hpp"

struct ChannelMap
{
    int throttle = 1;
    int steer = 0;
    int cmd = 7;
    int mode = 5;
    int mode_aux = 4;
    int shutdown = 2;

    int throttle_output = 1;
    int steer_output = 0;

    float steer_trim = -0.12;

    friend std::ostream& operator<<(std::ostream& os, const ChannelMap& p)
    {
        os << "throttle: "        << p.throttle        << ", "
           << "steer: "           << p.steer           << ", "
           << "cmd: "             << p.cmd             << ", "
           << "mode: "            << p.mode            << ", "
           << "mode_aux: "        << p.mode_aux        << ", "
           << "shutdown: "        << p.shutdown        << ", "
           << "throttle_output: " << p.throttle_output << ", "
           << "steer_output: "    << p.steer_output    << ", "
           << "steer_trim: "      << p.steer_trim;
        return os;
    }
};

class Configurations
{
public:
    bool load(std::string configFilePath)
    {
        std::ifstream configFile(configFilePath);
        if (configFile)
        {
            nlohmann::json jsonConfig;
            configFile >> jsonConfig;

            // rcin channels
            try {m_channelMap.throttle = jsonConfig.at("channelMap").at("throttle").get<int>();} catch (...) {}
            try {m_channelMap.steer    = jsonConfig.at("channelMap").at("steer").get<int>();} catch (...) {}
            try {m_channelMap.cmd      = jsonConfig.at("channelMap").at("cmd").get<int>();} catch (...) {}
            try {m_channelMap.mode     = jsonConfig.at("channelMap").at("mode").get<int>();} catch (...) {}
            try {m_channelMap.mode_aux = jsonConfig.at("channelMap").at("mode_aux").get<int>();} catch (...) {}
            try {m_channelMap.shutdown = jsonConfig.at("channelMap").at("shutdown").get<int>();} catch (...) {}

            // output channels
            try {m_channelMap.throttle_output = jsonConfig.at("channelMap").at("throttle_output").get<int>();} catch (...) {}
            try {m_channelMap.steer_output    = jsonConfig.at("channelMap").at("steer_output").get<int>();} catch (...) {}

            // trim
            try {m_channelMap.steer_trim    = jsonConfig.at("channelMap").at("steer_trim").get<float>();} catch (...) {}

            return true;
        }
        else
        {
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Configurations& p)
    {
        os << p.m_channelMap << std::endl;
        return os;
    }

    // channel map
    ChannelMap m_channelMap;
};