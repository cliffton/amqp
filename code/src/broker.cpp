//
// Created by cliffton on 5/5/18.
//

#include "broker.h"

using amqp::broker;

broker::broker(exchange::type ex_type) : exchange_{ex_type} {
    std::cout<< "Broker created!" << std::endl;
}