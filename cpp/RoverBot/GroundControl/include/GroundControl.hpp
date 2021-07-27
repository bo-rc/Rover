#pragma once

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdbool.h> /* required for the definition of bool in C99 */

/* This assumes you have the mavlink headers on your include path
 or in the same folder as this source file */
#include "common/mavlink.h"
#include "Types.hpp"

#include "OpMode_Sub.hpp"
#include "Power_Sub.hpp"
#include "Attitude_Sub.hpp"
#include "Position3d_Sub.hpp"
#include "Velocity3d_Sub.hpp"


#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

uint64_t microsSinceEpoch();


class GroundControl
{
	public:
		void step();
	
		GroundControl(std::string);

	private:
		void update_();
		std::string target_ip;
		int sock;
		struct sockaddr_in gcAddr;
		struct sockaddr_in locAddr;
		uint8_t buf[BUFFER_LENGTH];
		ssize_t recsize;
		socklen_t fromlen;
		mavlink_message_t msg;

		uint16_t len = 0;
		ssize_t bytes_sent = 0;

		uint64_t microsSinceEpoch();

		uint8_t id = 1;
		uint8_t component = 1;

		uint16_t load;
		uint16_t volt = 0;
		uint16_t current = 0;

		OpMode_Sub::OpMode_Sub m_OpMode_SubNode;
        OpMode m_currMode;

		Power_Sub::Power_Sub m_Power_SubNode;
		Power m_currPower;

		Attitude_Sub::Attitude_Sub m_Attitude_SubNode;
		Attitude m_currAtt;

		Position3d_Sub::Position3d_Sub m_Position3d_SubNode;
		Position3d m_currPos3d;

		Velocity3d_Sub::Velocity3d_Sub m_Velocity3d_SubNode;
		Velocity3d m_currVel3d;

		VehicleState m_currVehicleState;
};


