#include <iostream>
#include "src/broker.h"



using amqp::broker;
using amqp::exchange;

int main() {

    broker broker1(exchange::type::DIRECT);
    broker.run();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}