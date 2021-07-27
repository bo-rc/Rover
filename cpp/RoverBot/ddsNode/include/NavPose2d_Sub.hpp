#pragma once

#include "NodeSubscriber.hpp"
#include "NavPose2d_PubSubTypes.h"
#include "Types.hpp"

namespace NavPose2d_Sub
{
    class Listener : public SubListener<NavPose2d_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        NavPose2d pose;
    };

    static constexpr char nodeName[] = "NavPose2d_sub";
    static constexpr char topicName[] = "NavPose2d_topic";
    static constexpr char topicType[] = "NavPose2d_";

    class NavPose2d_Sub : public NodeSubscriber<NavPose2d_, NavPose2d_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(NavPose2d& pose);
    };
} // namespace NavPose2d_Sub