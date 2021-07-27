#pragma once

#include "NodePublisher.hpp"
#include "OpCmd_PubSubTypes.h"

namespace OpCmd_Pub
{
    const char nodeName[] = "OpCmd_pub";
    const char topicName[] = "OpCmd_topic";
    const char topicType[] = "OpCmd_";

    class OpCmd_Pub : public NodePublisher<OpCmd_, OpCmd_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(std::string cmd);

        //!Run the node
        void update(std::string cmd);
    };
} // namespace OpCmd_Pub