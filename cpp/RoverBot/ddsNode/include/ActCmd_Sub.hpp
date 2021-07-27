#pragma once

#include "NodeSubscriber.hpp"
#include "ActCmd_PubSubTypes.h"

namespace ActCmd_Sub
{
    class Listener : public SubListener<ActCmd_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        float steer_;
        float throttle_;
    };

    static constexpr char nodeName[] = "ActCmd_sub";
    static constexpr char topicName[] = "ActCmd_topic";
    static constexpr char topicType[] = "ActCmd_";

    class ActCmd_Sub : public NodeSubscriber<ActCmd_, ActCmd_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(float &steer, float &throttle);
    };
} // namespace ActCmd_Sub