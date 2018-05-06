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


std::shared_ptr<amqp_queue> exchange::bind_client(client& i_client, const string &binding_key) {
    auto queues = bindings_.find(binding_key);
    if (queues != bindings_.end()) {

        //Check if a queue already exists for this client.
        for (auto &queue: queues->second) {
            if (queue->getClientId() == i_client.get_id()) {
                return queue;
            }
        }
        std::shared_ptr<amqp_queue> q{new amqp_queue(i_client.get_id())};
        queues->second.emplace_back(q);
        return q;
    }
    else {
        //Create new Queue
        std::shared_ptr<amqp_queue> newQueue{new amqp_queue(i_client.get_id())};

        //Create Vector of Queues with input binding key.
        std::vector<std::shared_ptr<amqp_queue> > list;

        //push newly created queue on the vector
        list.emplace_back(newQueue);
        bindings_[binding_key] = list;
        return newQueue;
    }

}

/**
 * Send Message to all the the queues for which  binding key matches input message topic key.
 *
 * For example: Message of type: Fruit will be sent to queues with binding key Fruit.Orange, Fruit.Apple, Fruit
 * but  not to any other queue which does not have key that matches input message type pattern.
 *
 * @param msg: Message to be sent.
 */
void exchange::topic(message msg) {


    std::string criteria = msg.get_topic();
    for (auto queue : bindings_) {
        std::string::size_type n = queue.first.find(criteria);
        if(n != std::string::npos ) {
            for (auto q: queue.second) {
                q->add_message(msg);
            }
        }

    }


}

/**
 * Send message to the queue with exact same routing keys.
 * @param msg
 */
void exchange::direct(message msg) {
    auto queues = bindings_.find(msg.get_topic());
    if (queues != bindings_.end()) {
        for (auto q: queues->second) {
            q->add_message(msg);
        }
    }
}

/**
     * Send message to all queues
     * @param msg
     */
void exchange::fanout(message msg) {
    for (auto b : bindings_) {
        for (auto q : b.second) {
            q->add_message(msg);

        }
    }
}