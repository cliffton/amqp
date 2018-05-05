//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_EXCHANGE_H
#define CODE_EXCHANGE_H

#include <map>
#include "queue.h"

namespace amqp {
    class exchange {
    public:
        enum type {
            DIRECT,
            FAN_OUT,
            TOPIC
        };

        exchange(type ex_type) : type_{ex_type} {

        }

    private:
        type type_;
        std::map<std::string, amqp::queue> bindings_;
    };
}

#endif //CODE_EXCHANGE_H
