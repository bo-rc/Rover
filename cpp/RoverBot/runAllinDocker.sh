#!/bin/bash

Prefix='build/'

trap 'kill %1; kill %2; kill %3; kill %4; kill %5; kill %6; kill %7' SIGINT
$Prefix/AHRS/roverbot-AHRS | tee AHRS.log | sed -e 's/^/[AHRS] /' & \
$Prefix/BatteryMonitor/roverbot-BatteryMonitor | tee BatteryMonitor.log | sed -e 's/^/[Battery] /' & \
$Prefix/GroundControl/roverbot-GroundControl | tee GroundControl.log | sed -e 's/^/[Telemetry] /' & \
$Prefix/Localizer/roverbot-Localizer | tee Localizer.log | sed -e 's/^/[Localizer] /' & \
$Prefix/Navigator/roverbot-Navigator | tee Navigator.log | sed -e 's/^/[Navigator] /' & \
$Prefix/RCinput/roverbot-RCinput | tee RCinput.log | sed -e 's/^/[RCinput] /' & \
$Prefix/Actuator/roverbot-Actuator | tee Actuator.log | sed -e 's/^/[Actuator] /'