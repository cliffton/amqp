#ifndef AMQP_BROKER_H
#define AMQP_BROKER_H

#include <iostream>
#include "queue.h"
#include "exchange.h"


using amqp::exchange;



namespace amqp{
    class client;
}

using std::string;
using amqp::amqp_queue;

namespace amqp {

    /**
     * The broker is responsible for creating the
     * exchange and binding the queues to the exchange.
     * This should run as a thread
     * Will wait for messages on connections
     * and invoke the exchange.
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class broker {

    public:
        /*
         * Construct broker with input exchange type
         * @param: exchange type
         */
        broker(exchange::type etype);

        /*
        * Register all possible binding entered by user
        */

        void register_binding(const string &binding_key);

        /*
        * Register input client
        * @param client: input client
        * @param binding_key: input binding key
        */

        std::shared_ptr<amqp_queue> register_client(client &c, const string &binding_key);

        /*
         * publish the input message based on the message type and exchange type
         *
         * @param msg: input Message
         *
         */

        void publish(message msg);


        /*
         * end simulation method will be called once main thread has exited.
         * It will remove all the binding and queues.
         */
        void endSimulation();

        /*
         * Remove the binding corresponding to input binding key
         * @param: input binding key
         */
        void endBinding(string i_bindingKey);

    private:

        //Exchange associated with the broker.
        exchange exchange_;


    };
}


#endif //AMQP_BROKER_H
