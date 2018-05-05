//
// Created by cliffton on 5/5/18.
//

#include <iostream>
#include "exchange.h"

using amqp::exchange;

exchange::exchange(type etype): type_{etype} {
    std::cout<< "Exchange created!" << std::endl;
}