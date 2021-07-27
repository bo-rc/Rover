#pragma once
#include <iostream>

#include <iostream>
#include <memory>
#include <deque>

#include "Types.hpp"

class PIDCtrl
{
    public:
        PIDCtrl(float, float, float);
        PIDCtrl();
        ~PIDCtrl();
        
        // TODO: refactor as virtual sensor interface
        float compute(float curr, float tgt);
        float compute(NavPose2d curr, NavPose2d tgt);
        float compute(float error);

    private:
        // default is a P controller
        float m_P = 2.5; // largest possible heading error is PI
        float m_I = 0.5;
        float m_D = 0.;
        std::deque<float> m_error;
        size_t m_maxSize = 100;
};