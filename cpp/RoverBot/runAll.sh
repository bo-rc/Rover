#!/bin/bash

Prefix='./'
Configurations='../../Utils/Configurations.json'

trap 'kill %1; kill %2; kill %3; kill %4; kill %5; kill %6; kill %7' SIGINT
sudo $Prefix/roverbot-AHRS | tee AHRS.log | sed -e 's/^/[AHRS] /' & \
sudo $Prefix/roverbot-BatteryMonitor | tee BatteryMonitor.log | sed -e 's/^/[Battery] /' & \
sudo $Prefix/roverbot-GroundControl | tee GroundControl.log | sed -e 's/^/[Telemetry] /' & \
sudo $Prefix/roverbot-Localizer | tee Localizer.log | sed -e 's/^/[Localizer] /' & \
sudo $Prefix/roverbot-Navigator | tee Navigator.log | sed -e 's/^/[Navigator] /' & \
sudo $Prefix/roverbot-RCinput -c $Configurations | tee RCinput.log | sed -e 's/^/[RCinput] /' & \
sudo $Prefix/roverbot-Actuator -c $Configurations | tee Actuator.log | sed -e 's/^/[Actuator] /'
