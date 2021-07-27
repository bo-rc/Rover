#pragma once

#include "NodePublisher.hpp"
#include "NavPose2d_PubSubTypes.h"
#include "Types.hpp"

namespace NavPose2d_Pub
{
    static constexpr char nodeName[] = "NavPose2d_pub";
    static constexpr char topicName[] = "NavPose2d_topic";
    static constexpr char topicType[] = "NavPose2d_";

    class NavPose2d_Pub : public NodePublisher<NavPose2d_, NavPose2d_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(NavPose2d pose);

        //!Run the node
        void update(NavPose2d pose);
    };
} // namespace NavPose2d_Pub