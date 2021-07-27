#pragma once

#include "NodePublisher.hpp"
#include "ActCmd_PubSubTypes.h"

namespace ActCmd_Pub
{
    static constexpr char nodeName[] = "ActCmd_pub";
    static constexpr char topicName[] = "ActCmd_topic";
    static constexpr char topicType[] = "ActCmd_";

    class ActCmd_Pub : public NodePublisher<ActCmd_, ActCmd_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(float steer, float throttle);

        //!Run the node
        void update(float steer, float throttle);
    };
} // namespace ActCmd_Pub