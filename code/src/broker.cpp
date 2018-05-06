//
// Created by cliffton on 5/5/18.
//

#include "broker.h"

using amqp::broker;
bool broker::is_running = true;

broker::broker(exchange::type etype) : exchange_{etype} {
    std::cout << "Broker created!" << std::endl;
}

void broker::run() {

    std::cout << "Running " << std::endl;
    while (broker::is_running) {
        message msg = message("data", "x.x");
        exchange_.process_message(msg);
    }

}

void broker::setup() {

}

void broker::publish(message msg) {
    exchange_.process_message(msg);
}


void broker::register_binding(const string &binding_key) {
    exchange_.bind(binding_key);
}

void broker::register_client(client &c, const string &binding_key) {
    exchange_.bind_client(c, binding_key);
}