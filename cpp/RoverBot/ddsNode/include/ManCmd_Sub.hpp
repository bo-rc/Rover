#pragma once

#include "NodeSubscriber.hpp"
#include "ManCmd_PubSubTypes.h"

namespace ManCmd_Sub
{
    class Listener : public SubListener<ManCmd_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        float steer_;
        float throttle_;
    };

    static constexpr char nodeName[] = "ManCmd_sub";
    static constexpr char topicName[] = "ManCmd_topic";
    static constexpr char topicType[] = "ManCmd_";

    class ManCmd_Sub : public NodeSubscriber<ManCmd_, ManCmd_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(float &steer, float &throttle);
    };
} // namespace ManCmd_Sub