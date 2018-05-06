//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_EXCHANGE_H
#define CODE_EXCHANGE_H

#include <map>
#include "queue.h"
#include "message.h"
#include "client.h"

using amqp::amqp_queue;
using amqp::message;

namespace amqp {
    class exchange {
    public:

        enum type {
            DIRECT,
            FAN_OUT,
            TOPIC
        };

        /**
         * Constructor takes
         * exchange type as input.
         * @param ex_type
         */
        exchange(type etype);

        /**
         * Binds a queue to the give
         * binding key.
         * @param q
         * @param routing_key
         */
        void bind(const std::string &routing_key);

        void process_message(message msg);

        /**
         * Send message to all queues
         * @param msg
         */
        void fanout(message msg) ;

        /**
         * Send message to the queue with exact same routing keys.
         * @param msg
         */
        void direct(message msg);



        /**
         * Send Message to all the the queues for which  binding key matches input message topic key.
         *
         * For example: Message of type: Fruit will be sent to queues with binding key Fruit.Orange, Fruit.Apple, Fruit
         * but  not to any other queue which does not have key that matches input message type pattern.
         *
         * @param msg: Message to be sent.
         */
        void topic(message msg) ;


        std::shared_ptr<amqp_queue> bind_client(client &c, const string &binding_key);

    private:

        type type_;

        std::map<std::string, std::vector<std::shared_ptr<amqp_queue> > > bindings_;
    };
}

#endif //CODE_EXCHANGE_H
