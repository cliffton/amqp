#include "broker.h"

using amqp::broker;

/*
 * Construct broker with input exchange type
 * @param: exchange type
 */
broker::broker(exchange::type etype) : exchange_{etype} {
    std::cout << "Broker created!" << std::endl;
}


/*
 * Remove the binding corresponding to input binding key
 * @param: input binding key
 */
void amqp::broker::endBinding(string i_bindingKey) {
    exchange_.endBinding(i_bindingKey);
}

/*
 * end simulation method will be called once main thread has exited.
 * It will remove all the binding and queues.
 */
void amqp::broker::endSimulation() {
    exchange_.endSession();

}
/*
* publish the input message based on the message type and exchange type
*
* @param msg: input Message
*
*/
void broker::publish(message msg) {
    exchange_.process_message(msg);
}

/*
* Register all possible binding entered by user
*/

void broker::register_binding(const string &binding_key) {
    exchange_.bind(binding_key);
}

/*
* Register input client
* @param client: input client
* @param binding_key: input binding key
*/
std::shared_ptr<amqp_queue> broker::register_client(client &c, const string &binding_key) {
    return exchange_.bind_client(c, binding_key);
}