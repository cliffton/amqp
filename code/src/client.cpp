#include "client.h"
#include "message.h"
#include "broker.h"
#include <sstream>

using amqp::client;

unsigned int client::next_id = 1;

const string RECEIVED_DATA = "Received Data";




/*
 * Construct client.
 *
 * @param   i_name: name of the client
 * @param   i_bindingKey: binding key based on which messages will be routed
 * @param   i_broker: Reference to broker
 * @param   i_logger: Reference to the thread safe logger
 */
client::client(string i_name, string i_bindingKey,broker& i_broker, logger& i_logger) :
        id_{next_id++},
        name_{i_name},
        binding_key_{i_bindingKey},
        broker_{i_broker},
        logger_{i_logger}
{


    client_queue_ = broker_.register_client(*this, binding_key_);
    std::cout<<"Consumer "<< id_<<" has been created.";

}

/*
 * @return unique id for the client.
 */


unsigned int client::get_id() {
    return id_;
}

/*
 * Consume all the Messages from the linked queue and exit.
 * @return true if the read Message is DATA message and false if the read Message is CONTROL
 */
bool client::consume() {

    message readMessage = client_queue_->get_message();
    if(readMessage.getMessageType() == MessageType::DATA) {
        std::stringstream data;
        data<<"CL: "<<id_<<" Binding Key: "<<binding_key_<<" " <<RECEIVED_DATA<<" "<<readMessage.get_data();
        logger_.log(data.str());
        return true;
    }
    else {
        std::stringstream data;
        data<<"CL: "<<id_<<" Binding Key: "<<binding_key_<<" " <<"Exiting";
        logger_.log(data.str());
        return false;
    }

}

/*
 * Read all the message from the queue and exit when consume receives CONTROL message.
 */
void client::run() {

    while (consume()) {
    }
    //Once there is no more data inform broker



}




