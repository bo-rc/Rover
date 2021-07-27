#include "GroundControl.hpp"

GroundControl::GroundControl(std::string ip)
{
    target_ip = ip;
    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    fromlen = sizeof(gcAddr);
    memset(&locAddr, 0, sizeof(locAddr));
    locAddr.sin_family = AF_INET;
    locAddr.sin_addr.s_addr = INADDR_ANY;
    locAddr.sin_port = htons(14551);

    /* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */
    if (-1 == bind(sock, (struct sockaddr *)&locAddr, sizeof(struct sockaddr)))
    {
        perror("error bind failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (fcntl(sock, F_SETFL, O_NONBLOCK | O_ASYNC) < 0)
    {
        fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
        close(sock);
        exit(EXIT_FAILURE);
    }

    memset(&gcAddr, 0, sizeof(gcAddr));
    gcAddr.sin_family = AF_INET;
    gcAddr.sin_addr.s_addr = inet_addr(target_ip.c_str());
    gcAddr.sin_port = htons(14550);
}

void GroundControl::update_()
{
    m_OpMode_SubNode.update(m_currMode);
    m_Power_SubNode.update(m_currPower);
    m_Attitude_SubNode.update(m_currAtt);
    m_Position3d_SubNode.update(m_currPos3d);
    m_Velocity3d_SubNode.update(m_currVel3d);

    m_currVehicleState.roll = m_currAtt.roll;
    m_currVehicleState.pitch = m_currAtt.pitch;
    m_currVehicleState.yaw = m_currAtt.yaw;

    m_currVehicleState.x = m_currPos3d.x;
    m_currVehicleState.y = m_currPos3d.y;
    m_currVehicleState.z = m_currPos3d.z;

    m_currVehicleState.vx = m_currVel3d.x;
    m_currVehicleState.vy = m_currVel3d.y;
    m_currVehicleState.vz = m_currVel3d.z;
}

void GroundControl::step()
{
    /*Send Heartbeat */
    update_();
    int mode = 0;
    if (m_currMode == OpMode::Manual or m_currMode == OpMode::Clear)
    {
        mode = MAV_MODE::MAV_MODE_MANUAL_ARMED;
    }
    else if (m_currMode == OpMode::Waypoint)
    {
        mode = MAV_MODE::MAV_MODE_AUTO_ARMED;
    }
    else if (m_currMode == OpMode::Continue or m_currMode == OpMode::Reset)
    {
        mode = MAV_MODE::MAV_MODE_GUIDED_ARMED;
    }
    else if (m_currMode == OpMode::ManualDisarmed)
    {
        mode = MAV_MODE::MAV_MODE_MANUAL_DISARMED;
    }
    else if (m_currMode == OpMode::AutoDisarmed)
    {
        mode = MAV_MODE::MAV_MODE_AUTO_DISARMED;
    }

    volt = m_currPower.batVolt;
    current = m_currPower.batCurrent;

    /* Send Status */
    mavlink_msg_heartbeat_pack(id, component, &msg, MAV_TYPE_GROUND_ROVER, MAV_AUTOPILOT_GENERIC, mode, 0, MAV_STATE_ACTIVE);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr *)&gcAddr, sizeof(struct sockaddr_in));

    mavlink_msg_sys_status_pack(id, component, &msg, 1, 1, 1, load, volt, current, -1, 0, 0, 0, 0, 0, 0);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr *)&gcAddr, sizeof(struct sockaddr_in));

    /* Send Local Position */
    mavlink_msg_local_position_ned_pack(id, component, &msg, microsSinceEpoch(),
                                        m_currVehicleState.x, m_currVehicleState.y, m_currVehicleState.z,
                                        m_currVehicleState.vx, m_currVehicleState.vy, m_currVehicleState.vz);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr *)&gcAddr, sizeof(struct sockaddr_in));

    /* Send attitude */
    mavlink_msg_attitude_pack(id, component, &msg, microsSinceEpoch(), m_currVehicleState.roll, m_currVehicleState.pitch, m_currVehicleState.yaw,
                              m_currVehicleState.vRoll, m_currVehicleState.vPitch, m_currVehicleState.vYaw);

    len = mavlink_msg_to_send_buffer(buf, &msg);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr *)&gcAddr, sizeof(struct sockaddr_in));

    // printf("sent %d", (int)bytes_sent);

    memset(buf, 0, BUFFER_LENGTH);

    // receiver disabled for now
    if (false)
    {
        recsize = recvfrom(sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen);
        if (recsize > 0 && false)
        {
            // Something received - print out all bytes and parse packet
            mavlink_message_t msg;
            mavlink_status_t status;

            printf("Bytes Received: %d\nDatagram: ", (int)recsize);
            for (int i = 0; i < recsize; ++i)
            {
                auto temp = buf[i];
                printf("%02x ", (unsigned char)temp);
                if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
                {
                    // Packet received
                    printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
                }
            }
            printf("\n");
        }
        memset(buf, 0, BUFFER_LENGTH);
    }
}

uint64_t GroundControl::microsSinceEpoch()
{

    struct timeval tv;

    uint64_t micros = 0;

    gettimeofday(&tv, NULL);
    micros = ((uint64_t)tv.tv_sec) * 1000000 + tv.tv_usec;

    return micros;
}