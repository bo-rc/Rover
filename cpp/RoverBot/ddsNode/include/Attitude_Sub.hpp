#pragma once

#include "NodeSubscriber.hpp"
#include "Attitude_PubSubTypes.h"
#include "Types.hpp"

namespace Attitude_Sub
{
    class Listener : public SubListener<Attitude_>
    {
    public:
        // need an override implementation for each inherited class.
        void on_data_available(DataReader *reader) override;

        // need data holders
        Attitude att;
    };

    static constexpr char nodeName[] = "Attitude_sub";
    static constexpr char topicName[] = "Attitude_topic";
    static constexpr char topicType[] = "Attitude_";

    class Attitude_Sub : public NodeSubscriber<Attitude_, Attitude_PubSubType, Listener, nodeName, topicName, topicType>
    {
    public:
        //!Run the node
        void update(Attitude& att);
    };
} // namespace Attitude_Sub