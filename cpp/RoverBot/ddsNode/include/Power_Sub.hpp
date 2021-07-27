#pragma once

#include "NodeSubscriber.hpp"
#include "Power_PubSubTypes.h"
#include "Types.hpp"

namespace Power_Sub
{
    class Listener : public SubListener<Power_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        Power power;
    };

    static constexpr char nodeName[] = "Power_sub";
    static constexpr char topicName[] = "Power_topic";
    static constexpr char topicType[] = "Power_";

    class Power_Sub : public NodeSubscriber<Power_, Power_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(Power& power);
    };
} // namespace Power_Sub