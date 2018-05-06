//
// Created by cliffton on 5/5/18.
//

#include <iostream>
#include "exchange.h"

using amqp::exchange;

exchange::exchange(type etype): type_{etype} {
    std::cout<< "Exchange created!" << std::endl;
}

//void exchange::bind(amqp_queue q, const std::string &routing_key) {
//    bindings_[routing_key]
//}