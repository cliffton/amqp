//
// Created by cliffton on 5/5/18.
//

#ifndef AMQP_BROKER_H
#define AMQP_BROKER_H

#include <iostream>
#include "exchange.h"
#include "client.h"

using amqp::exchange;
using amqp::client;

namespace amqp {

    /**
     * This should run as a thread
     * Will wait for messages on connections
     * and invoke the exchange.
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
