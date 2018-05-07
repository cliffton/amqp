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
        broker(exchange::type etype);

        void register_binding(const string &binding_key);

        std::shared_ptr<amqp_queue> register_client(client &c, const string &binding_key);


        void publish(message msg);

        void run();

        static bool is_running;

        void endSimulation();

    private:

        exchange exchange_;


    };
}


#endif //AMQP_BROKER_H
