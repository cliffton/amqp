#ifndef CODE_MESSAGE_H
#define CODE_MESSAGE_H

#include <string>

using std::string;

namespace amqp {


    enum MessageType {
        DATA,
        CONTROL
    };

    /**
     * As the name suggests it is the message/entity that is passed
     * from the producer to the consumers in the system.
     * Each message can have multiple properties but should
     * contain a routing key and the message data.
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class message {


    public:
        message(string data, string topic, MessageType type);

        message(string data, string topic);

        string get_data() const;

        string get_topic() const;

        unsigned int get_count() const;

        void increment_count();

        void setMessageType();

        amqp::MessageType getMessageType();


    private:
        string data_;
        string topic_;
        unsigned int count_{};

        MessageType type_;


    };
};

#endif //CODE_MESSAGE_H
