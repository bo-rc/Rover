#pragma once

#include "NodePublisher.hpp"
#include "ManCmd_PubSubTypes.h"

namespace ManCmd_Pub
{
    static constexpr char nodeName[] = "ManCmd_pub";
    static constexpr char topicName[] = "ManCmd_topic";
    static constexpr char topicType[] = "ManCmd_";

    class ManCmd_Pub : public NodePublisher<ManCmd_, ManCmd_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(float steer, float throttle);

        //!Run the node
        void update(float steer, float throttle);
    };
} // namespace ManCmd_Pub