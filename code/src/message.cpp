#include <iostream>
#include "message.h"

using amqp::message;

message::message(string data, string topic, MessageType type) : data_{data}, topic_{topic},type_{type} {
    std::cout << "Message created!" << std::endl;
}

message::message(string data, string topic) : message(data,topic,MessageType::DATA)  {
    std::cout << "Message created!" << std::endl;
}

string message::get_data() const {
    return data_;
}

string message::get_topic() const {
    return topic_;
}

unsigned int message::get_count() const {
    return count_;
}


void message::increment_count() {
    count_++;
}

amqp::MessageType message::getMessageType() {
    return type_;
}