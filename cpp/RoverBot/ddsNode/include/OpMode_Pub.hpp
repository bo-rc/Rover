#pragma once

#include "NodePublisher.hpp"
#include "OpMode_PubSubTypes.h"

namespace OpMode_Pub
{
    const char nodeName[] = "OpMode_pub";
    const char topicName[] = "OpMode_topic";
    const char topicType[] = "OpMode_";

    class OpMode_Pub : public NodePublisher<OpMode_, OpMode_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(std::string mode);

        //!Run the node
        void update(std::string mode);
    };
} // namespace OpMode_Pub