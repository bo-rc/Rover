#pragma once

#include "NodePublisher.hpp"
#include "Power_PubSubTypes.h"

namespace Power_Pub
{
    static constexpr char nodeName[] = "Power_pub";
    static constexpr char topicName[] = "Power_topic";
    static constexpr char topicType[] = "Power_";

    class Power_Pub : public NodePublisher<Power_, Power_PubSubType, nodeName, topicName, topicType>
    {
    public:
        //!Send a publication
        bool publish(float boardVolt, float railVolt, float batVolt, float batCurrent);

        //!Run the node
        void update(float boardVolt, float railVolt, float batVolt, float batCurrent);
    };
} // namespace Power_Pub