#pragma once

#include "NodeSubscriber.hpp"
#include "Position3d_PubSubTypes.h"
#include "Types.hpp"

namespace Position3d_Sub
{
    class Listener : public SubListener<Position3d_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        Position3d pose;
    };

    static constexpr char nodeName[] = "Position3d_sub";
    static constexpr char topicName[] = "Position3d_topic";
    static constexpr char topicType[] = "Position3d_";

    class Position3d_Sub : public NodeSubscriber<Position3d_, Position3d_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(Position3d& pose);
    };
} // namespace Position3d_Sub