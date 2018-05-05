//
// Created by cliffton on 5/5/18.
//

#ifndef AMQP_BROKER_H
#define AMQP_BROKER_H

#include <iostream>
#include "exchange.h"

using amqp::exchange;

namespace amqp {

    /**
     * This should run as a thread
     * Will wait for messages on connections
     * and invoke the exchange.
     */
    class broker {

        broker(exchange::type ex_type);


    private:
        exchange exchange_;

    };
}


#endif //AMQP_BROKER_H
