//
// Created by cliffton on 5/5/18.
//

#include "client.h"

using amqp::client;

unsigned int client::next_id = 1;


client::client(string i_name, string i_bindingKey,broker& i_broker, logger& i_logger) :
        id_{next_id++},
        name_{i_name},
        binding_key_{i_bindingKey},
        broker_{i_broker},
        logger_{i_logger}
{


    broker_.register_client(*this, binding_key_);


}


unsigned int client::get_id() {
    return id_;
}

void client::consume() {

}

void client::run() {
    while (true) {
        consume();
    }

}




