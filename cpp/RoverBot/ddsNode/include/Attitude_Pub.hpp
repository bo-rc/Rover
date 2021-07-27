#pragma once

#include "NodePublisher.hpp"
#include "Attitude_PubSubTypes.h"
#include "Types.hpp"

namespace Attitude_Pub
{
    static constexpr char nodeName[] = "Attitude_pub";
    static constexpr char topicName[] = "Attitude_topic";
    static constexpr char topicType[] = "Attitude_";

    class Attitude_Pub : public NodePublisher<Attitude_, Attitude_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(Attitude att);

        //!Run the node
        void update(Attitude att);
    };
} // namespace Attitude_Pub