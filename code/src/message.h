#ifndef CODE_MESSAGE_H
#define CODE_MESSAGE_H

#include <string>

using std::string;

namespace amqp {

    /*
     * define the Message type
     *
     * DATA:    This type is used by default to exchange data between producer and consumer.
     * CONTROL: This type is used to inform the client that there is no more data.
     */

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
     * There are 2 types of Messages:
     *  - DATA:    This type is used by default to exchange data between producer and consumer.
     *  - CONTROL: This type is used to inform the client that there is no more data.
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class message {


    public:

        /*
         * Construct a Message
         *
         * @param data: input data that is to be wrapped.
         * @param topic: topic of the Message, a message will be routed based on it's topic.
         * @param type: type of the Message i.e. DATA or Control
         */
        message(string data, string topic, MessageType type);


        /*
         * Construct a  DATA Message
         *
         * @param data: input data that is to be wrapped.
         * @param topic: topic of the Message, a message will be routed based on it's topic.
         *
         */

        message(string data, string topic);

        /*
         * @return Return data wrapped in the message
         */

        string get_data() const;

        /*
         * @return Return message topic.
         */

        string get_topic() const;

        /*
         * @return Message type DATA or CONTROL
         */
        MessageType getMessageType();


    private:

        //Data wrapped in the message
        string data_;

        //Message topic.
        string topic_;

        //Message type DATA or CONTROL
        amqp::MessageType type_;


    };
};

#endif //CODE_MESSAGE_H
