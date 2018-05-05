#include <iostream>
//#include "src/broker.h"
#include "thread"
#include "src/exchange.h"

using std::thread;
//using amqp::broker;
using amqp::exchange;

int main() {

//    broker b(exchange::type::DIRECT);
//    thread t(&broker::run, b);
//    t.join();
    amqp::exchange ex{exchange::DIRECT};
    return 0;
}