//
// Created by cliffton on 5/5/18.
//

#include <iostream>
#include "exchange.h"

using amqp::exchange;

exchange::exchange(type etype) : type_{etype} {
    std::cout << "Exchange created!" << std::endl;
}

void exchange::bind(const std::string &routing_key) {
    std::vector<std::shared_ptr<amqp_queue> > q;
    bindings_.insert(std::make_pair(routing_key, q));
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


std::shared_ptr<amqp_queue> exchange::bind_client(client& c, const string &binding_key) {
    auto queues = bindings_.find(binding_key);
    if (queues != bindings_.end()) {
        std::shared_ptr<amqp_queue> q {new amqp_queue(c.get_id())};
        queues->second.emplace_back(q);
        return q;
    }
    else {

    }
}