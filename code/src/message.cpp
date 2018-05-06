//
// Created by cliffton on 5/5/18.
//

#include <iostream>
#include "message.h"

using amqp::message;

message::message(string &data, string &topic) : data_{data}, topic_{topic} {
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