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


void exchange::process_message(amqp::message msg) {
    // find routing key in bindings
    auto queues = bindings_.find(msg.get_topic());
    if (queues != bindings_.end()) {
        // depending on type of exchange deliver msg to bounded queues.
    }

}