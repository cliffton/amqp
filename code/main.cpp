#include <iostream>
#include "thread"
#include "src/broker.h"

using std::thread;
using amqp::broker;
using amqp::exchange;

int main() {

    broker b(exchange::type::DIRECT);
    b.setup();
    thread t(&broker::run, b);
    t.join();
    return 0;
}