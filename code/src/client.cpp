//
// Created by cliffton on 5/5/18.
//

#include "client.h"

using amqp::client;

unsigned int client::next_id = 1;

client::client(const string &name, const string &binding_key) :
        id_{next_id++},
        name_{name},
        binding_key_{binding_key},
        thread_{} {

}


unsigned int client::get_id() {
    return id_;
}

void client::consume() {

}

void client::run() {
    while (is_running) {
        consume();
    }

}

void client::stop() {
    is_running = false;
}

client::~client() {
    if (thread_.joinable()) {
        thread_.join();
    }
}

void client::join() {
    if (thread_.joinable()) {
        thread_.join();
    }
}

void client::start() {
    thread_ = thread{&client::run, this};
}