#include <iostream>
#include "thread"
#include "src/broker.h"
#include "src/client.h"


using std::thread;
using amqp::broker;
using amqp::exchange;
using amqp::client;

int main() {

    broker b(exchange::type::DIRECT);
    // Do you want to create
    unsigned int clients;
    unsigned int queue_count;
    std::cout << "Number of bindings ?";
    std::cin >> queue_count;
    while (queue_count--) {
        std::string binding_key;
        std::cout << "Please provide key binding:";
        std::cin >> binding_key;
        b.register_binding(binding_key);
    }

    std::cout << "Number of clients ?";
    std::cin >> clients;
    while (clients--) {
        std::string client_name;
        std::cout << "Please provide client name:";
        std::cin >> client_name;
        std::string binding_key;
        std::cout << "Please provide client key binding:";
        std::cin >> binding_key;
        client c{client_name, binding_key};
        b.register_client(c, binding_key);
    }
    b.setup();
    thread t(&broker::run, b);
    t.join();
    return 0;
}