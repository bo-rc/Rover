#pragma once

#include "NodeSubscriber.hpp"
#include "OpCmd_PubSubTypes.h"
#include "Types.hpp"

namespace OpCmd_Sub
{
    class Listener : public SubListener<OpCmd_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        OpCmd cmd;
    };

    static constexpr char nodeName[] = "OpCmd_sub";
    static constexpr char topicName[] = "OpCmd_topic";
    static constexpr char topicType[] = "OpCmd_";

    class OpCmd_Sub : public NodeSubscriber<OpCmd_, OpCmd_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(OpCmd& cmd);
    };
} // namespace OpCmd_Sub