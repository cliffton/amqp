//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_EXCHANGE_H
#define CODE_EXCHANGE_H

#include <map>
#include "queue.h"
#include "message.h"

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
        void bind(amqp::queue q, const std::string &routing_key);


        void process_message(amqp::message msg);

    private:
        type type_;
        std::map<std::string, amqp::queue> bindings_;
    };
}

#endif //CODE_EXCHANGE_H
