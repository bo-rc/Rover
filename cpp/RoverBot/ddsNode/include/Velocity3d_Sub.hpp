#pragma once

#include "NodeSubscriber.hpp"
#include "Velocity3d_PubSubTypes.h"
#include "Types.hpp"

namespace Velocity3d_Sub
{
    class Listener : public SubListener<Velocity3d_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        Velocity3d vel;
    };

    static constexpr char nodeName[] = "Velocity3d_sub";
    static constexpr char topicName[] = "Velocity3d_topic";
    static constexpr char topicType[] = "Velocity3d_";

    class Velocity3d_Sub : public NodeSubscriber<Velocity3d_, Velocity3d_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(Velocity3d& vel);
    };
} // namespace Velocity3d_Sub