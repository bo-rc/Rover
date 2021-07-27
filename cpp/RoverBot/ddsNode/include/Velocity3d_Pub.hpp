#pragma once

#include "NodePublisher.hpp"
#include "Velocity3d_PubSubTypes.h"
#include "Types.hpp"

namespace Velocity3d_Pub
{
    static constexpr char nodeName[] = "Velocity3d_pub";
    static constexpr char topicName[] = "Velocity3d_topic";
    static constexpr char topicType[] = "Velocity3d_";

    class Velocity3d_Pub : public NodePublisher<Velocity3d_, Velocity3d_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(Velocity3d vel);

        //!Run the node
        void update(Velocity3d vel);
    };
} // namespace Velocity3d_Pub