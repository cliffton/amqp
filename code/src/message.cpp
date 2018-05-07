#include <iostream>
#include "message.h"

using amqp::message;

/**
* As the name suggests it is the message/entity that is passed
* from the producer to the consumers in the system.
* Each message can have multiple properties but should
* contain a routing key and the message data.
*
* @authors Manpreet Kaur, Cliffton Fernandes
*
*/


/*
 * Construct a Message
 *
 * @param data: input data that is to be wrapped.
 * @param topic: topic of the Message, a message will be routed based on it's topic.
 * @param type: type of the Message i.e. DATA or Control
 */
message::message(string data, string topic, MessageType type) : data_{data}, topic_{topic},type_{type} {
    std::cout << "Message created!" << std::endl;
}

/*
 * Construct a  DATA Message
 *
 * @param data: input data that is to be wrapped.
 * @param topic: topic of the Message, a message will be routed based on it's topic.
 *
 */

message::message(string data, string topic) : message(data,topic,MessageType::DATA)  {
    std::cout << "Message created!" << std::endl;
}


/*
 * @return Return data wrapped in the message
 */
string message::get_data() const {
    return data_;
}

/*
 * @return Return message topic.
 */

string message::get_topic() const {
    return topic_;
}

/*
 * @return Message type
 */
amqp::MessageType amqp::message::getMessageType() {
    return type_;
}
