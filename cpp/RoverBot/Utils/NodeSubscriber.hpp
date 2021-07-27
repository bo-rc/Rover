#pragma once

#include <typeinfo>

// DDS includes
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

using namespace eprosima::fastdds::dds;

template <typename TopicClass>
class SubListener : public DataReaderListener
{
public:
    SubListener()
    {
    }

    ~SubListener() override
    {
    }

    void on_subscription_matched(
        DataReader *,
        const SubscriptionMatchedStatus &info) override
    {
        if (info.current_count_change == 1)
        {
            std::cout << typeid(TopicClass).name() << " Subscriber matched." << std::endl;
        }
        else if (info.current_count_change == -1)
        {
            std::cout << typeid(TopicClass).name() << "Subscriber unmatched." << std::endl;
        }
        else
        {
            std::cout << typeid(TopicClass).name() << " " << info.current_count_change
                      << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
        }
    }
    
    // // need an override implementation for each inherited class.
    // void on_data_available(DataReader *reader) override
    // {
    //     SampleInfo info;
    //     if (reader->take_next_sample(&msg_, &info) == ReturnCode_t::RETCODE_OK)
    //     {
    //         if (info.instance_state == ALIVE)
    //         {
    //             steer_ = msg_.steer();
    //             throttle_ = msg_.throttle();
    //         }
    //     }
    // }

    // // need data holders
    // float steer_;
    // float throttle_;

    TopicClass msg_;
};

template <typename TopicClass, typename TopicPubSubType, typename SubListenerImpl, const char *nodeName, const char *topicName, const char *topicType>
class NodeSubscriber
{
protected:
    // DDS
    TopicClass msg_;

    DomainParticipant *participant_;
    Subscriber *subscriber_;
    DataReader *reader_;
    Topic *topic_;
    TypeSupport type_;
    SubListenerImpl listener_;

public:
    NodeSubscriber()
        : participant_(nullptr), subscriber_(nullptr), topic_(nullptr), reader_(nullptr), type_(new TopicPubSubType())
    {
        init();
    }

    virtual ~NodeSubscriber()
    {
        if (reader_ != nullptr)
        {
            subscriber_->delete_datareader(reader_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        if (subscriber_ != nullptr)
        {
            participant_->delete_subscriber(subscriber_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    //!Initialize the subscriber
    bool init()
    {
        DomainParticipantQos participantQos;
        participantQos.name(nodeName);
        participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

        if (participant_ == nullptr)
        {
            return false;
        }

        // Register the Type
        type_.register_type(participant_);

        // Create the subscriptions Topic
        topic_ = participant_->create_topic(topicName, topicType, TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        // Create the Subscriber
        subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

        if (subscriber_ == nullptr)
        {
            return false;
        }

        // Create the DataReader
        reader_ = subscriber_->create_datareader(topic_, DATAREADER_QOS_DEFAULT, &listener_);

        if (reader_ == nullptr)
        {
            return false;
        }

        return true;
    }

    // //!implement void update();
    // void update(float &steer, float &throttle)
    // {
    //     steer = listener_.steer_;
    //     throttle = listener_.throttle_;
    // }
};