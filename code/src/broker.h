#ifndef AMQP_BROKER_H
#define AMQP_BROKER_H

#include <iostream>
#include "exchange.h"
#include "client.h"

using amqp::exchange;
using amqp::client;

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

        void setup();

        void publish(message msg);

        void run();

        static bool is_running;

    private:
        exchange exchange_;

    };
}


#endif //AMQP_BROKER_H
