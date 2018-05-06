#include <iostream>
#include "thread"
#include "src/broker.h"
#include "src/client.h"


using std::thread;
using amqp::broker;
using amqp::exchange;
using amqp::client;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;


int main() {

    broker b(exchange::type::DIRECT);
    // Do you want to create
    std::vector<thread> clients;
    unsigned int client_count;
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
    std::cin >> client_count;
    while (client_count--) {
        std::string client_name;
        std::cout << "Please provide client name:";
        std::cin >> client_name;
        std::string binding_key;
        std::cout << "Please provide client key binding:";
        std::cin >> binding_key;
        client c{client_name, binding_key};
        thread ct{&client::run, c};
        clients.emplace_back(std::move(ct));
        b.register_client(c, binding_key);

    }
    b.setup();
    thread bt(&broker::run, b);
    sleep_for(milliseconds(10000));
    broker::is_running = false;
    bt.join();
    for (auto &ct : clients) {
        ct.join();
    }

    return 0;
}