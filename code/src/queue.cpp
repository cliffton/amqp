//
// Created by cliffton on 5/5/18.
//

#include "queue.h"


using amqp::amqp_queue;

amqp_queue::amqp_queue(unsigned int client_id) : client_id_{client_id} {
    std::cout << "Created AMQP Queue!" << std::endl;
}


void amqp_queue::add_message(message msg) {
    // TODO: Make thread safe.
    internal_queue_.push(msg);
}

message amqp_queue::get_message() {
    // TODO: Figure out multiple consumers.
    message msg = internal_queue_.front();
    internal_queue_.pop();
    return msg;
}