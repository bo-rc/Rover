#pragma once

#include "NodePublisher.hpp"
#include "Position3d_PubSubTypes.h"
#include "Types.hpp"

namespace Position3d_Pub
{
    static constexpr char nodeName[] = "Position3d_pub";
    static constexpr char topicName[] = "Position3d_topic";
    static constexpr char topicType[] = "Position3d_";

    class Position3d_Pub : public NodePublisher<Position3d_, Position3d_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(Position3d pose);

        //!Run the node
        void update(Position3d pose);
    };
} // namespace Position3d_Pub