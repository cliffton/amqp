//
// Created by cliffton on 5/5/18.
//

#include "client.h"
#include "message.h"

using amqp::client;

unsigned int client::next_id = 1;

const string RECEIVED_DATA = "Received Data";




client::client(string i_name, string i_bindingKey,broker& i_broker, logger& i_logger) :
        id_{next_id++},
        name_{i_name},
        binding_key_{i_bindingKey},
        broker_{i_broker},
        logger_{i_logger}
{


    client_queue_ = broker_.register_client(*this, binding_key_);

}


unsigned int client::get_id() {
    return id_;
}

bool client::consume() {

    message readMessage = client_queue_->get_message();
    if(readMessage.getMessageType() == MessageType::DATA) {
        logger_.log(std::string("CL:" + id_ ) + RECEIVED_DATA +  readMessage.get_data());
        return true;
    }
    else {
        logger_.log(std::string("CL:" + id_ ) + RECEIVED_DATA + std::string("Control Message!") );
        logger_.log(std::string("CL:" + id_ + std::string("Exiting")));
        return false;
    }

}

void client::run() {
    while (consume()) {
    }

}




