//
// Created by cliffton on 5/5/18.
//

#include <iostream>
#include "exchange.h"

using amqp::exchange;

exchange::exchange(type etype) : type_{etype} {
    std::cout << "Exchange created!" << std::endl;
}

void exchange::bind(amqp_queue q, const std::string &routing_key) {
    bindings_[routing_key].emplace_back(q);
}


void exchange::process_message(message msg) {
    // find routing key in bindings
    // depending on type of exchange deliver msg to bounded queues.
    if (type_ == type::FAN_OUT) {
        fanout(msg);
    } else if (type_ == type::DIRECT) {
        direct(msg);
    } else if (type_ == type::TOPIC) {
        topic(msg);
    }

}
