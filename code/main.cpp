#include <iostream>
#include "thread"
#include "src/broker.h"

using std::thread;
using amqp::broker;
using amqp::exchange;

int main() {

    broker b(exchange::type::DIRECT);
    // Do you want to create
    unsigned int clients;
    unsigned int queue_count;
    std::cout << "Number of clients ?";
    std::cin >> clients;
    std::cout << "Number of bindings ?";
    std::cin >> queue_count;
    while (queue_count--) {
        std::string binding_key;
        std::cout << "Please provide key binding:";
        std::cin >> binding_key;
        b.register_binding(binding_key);
    }
    b.setup();
    thread t(&broker::run, b);
    t.join();
    return 0;
}