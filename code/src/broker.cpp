//
// Created by cliffton on 5/5/18.
//

#include "broker.h"

using amqp::broker;

broker::broker(exchange::type etype) : exchange_{etype} {
    std::cout << "Broker created!" << std::endl;
}

void broker::run() {

    std::cout << "Running " << std::endl;

}