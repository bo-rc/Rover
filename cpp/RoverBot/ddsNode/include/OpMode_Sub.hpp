#pragma once

#include "NodeSubscriber.hpp"
#include "OpMode_PubSubTypes.h"
#include "Types.hpp"

namespace OpMode_Sub
{
    class Listener : public SubListener<OpMode_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        OpMode mode;
    };

    static constexpr char nodeName[] = "OpMode_sub";
    static constexpr char topicName[] = "OpMode_topic";
    static constexpr char topicType[] = "OpMode_";

    class OpMode_Sub : public NodeSubscriber<OpMode_, OpMode_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(OpMode& mode);
    };
} // namespace OpMode_Sub