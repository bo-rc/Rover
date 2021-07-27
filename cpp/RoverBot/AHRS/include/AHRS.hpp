/*
Mahony AHRS algorithm implemented by Madgwick
See: http://x-io.co.uk/open-source-imu-and-ahrs-algorithms/
Adapted by Igor Vereninov (igor.vereninov@emlid.com)
Provided to you by Emlid Ltd (c) 2014.
twitter.com/emlidtech || www.emlid.com || info@emlid.com
*/

#ifndef AHRS_HPP
#define AHRS_HPP

#include <cmath>
#include <stdio.h>
#include <memory>
#include <InertialSensor.h>
#include "Attitude_Pub.hpp"

class AHRS{
private:
	float q0, q1, q2, q3;
	float gyroOffset[3];
	float twoKi;
	float twoKp;
	float integralFBx, integralFBy, integralFBz;
    std::unique_ptr <InertialSensor> sensor;

    bool init();
    void setGyroOffset();
    void update(float dt);
    void updateIMU(float dt);
    float invSqrt(float x);
    void getEuler();
public:
    AHRS();
    void step();

    // data store
    float m_roll;
    float m_pitch;
    float m_yaw;

    Attitude_Pub::Attitude_Pub m_Attitude_PubNode;
};

#endif // AHRS_hpp