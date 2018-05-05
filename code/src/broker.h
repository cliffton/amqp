//
// Created by cliffton on 5/5/18.
//

#ifndef AMQP_BROKER_H
#define AMQP_BROKER_H

#include <iostream>
#include "exchange.h"

using amqp::exchange;

namespace amqq {

    class broker {

        broker(exchange::type ex_type) : exchange_{ex_type} {
            std::cout << ex_type << std::endl;
        }

    private:
        exchange exchange_;

    };
}


#endif //AMQP_BROKER_H
