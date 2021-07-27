#pragma once

#include <typeinfo>

// DDS includes
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>

using namespace eprosima::fastdds::dds;

template <typename TopicClass>
class PubListener : public DataWriterListener
{
public:
    PubListener()
        : matched_(0)
    {
    }

    ~PubListener() override
    {
    }

    void on_publication_matched(
        DataWriter *,
        const PublicationMatchedStatus &info) override
    {
        if (info.current_count_change == 1)
        {
            matched_ = info.total_count;
            std::cout << typeid(TopicClass).name() << " Publisher matched." << std::endl;
        }
        else if (info.current_count_change == -1)
        {
            matched_ = info.total_count;
            std::cout << typeid(TopicClass).name() << " Publisher unmatched." << std::endl;
        }
        else
        {
            std::cout << typeid(TopicClass).name() << " " << info.current_count_change
                      << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
        }
    }

    std::atomic_int matched_;
};

template <typename TopicClass, typename TopicPubSubType, const char *nodeName, const char *topicName, const char *topicType>
class NodePublisher
{
protected:
    // DDS
    TopicClass msg_;

    DomainParticipant *participant_;
    Publisher *publisher_;
    DataWriter *writer_;
    Topic *topic_;
    TypeSupport type_;
    PubListener<TopicClass> listener_;

public:
    NodePublisher()
        : participant_(nullptr), publisher_(nullptr), topic_(nullptr), writer_(nullptr), type_(new TopicPubSubType())
    {
        init();
    }

    virtual ~NodePublisher()
    {
        if (writer_ != nullptr)
        {
            publisher_->delete_datawriter(writer_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        if (publisher_ != nullptr)
        {
            participant_->delete_publisher(publisher_);
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
        publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);

        if (publisher_ == nullptr)
        {
            return false;
        }

        // Create the DataReader
        writer_ = publisher_->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT, &listener_);

        if (writer_ == nullptr)
        {
            return false;
        }

        return true;
    }

    //!implement bool publish();

    //!implement void update();
};