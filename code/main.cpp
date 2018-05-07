#include <iostream>
#include "thread"
#include "src/broker.h"
#include "src/client.h"
#include "src/logger.h"
#include "src/producer.h"

using std::thread;
using amqp::broker;
using amqp::exchange;
using amqp::client;
using amqp::producer;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;


int main() {

    logger logger_{std::cout};

    int extype;
    exchange::type t;
    std::cout << "Please provide exchange type: \n 0: FANOUT \n 1: DIRECT \n 2: TOPIC \n >" ;
    std::cin >> extype;
    if (extype == 0) {
        t = exchange::type::FAN_OUT;
    }
    if (extype == 1) {
        t = exchange::type::DIRECT;
    }
    if (extype == 3) {
        t = exchange::type::TOPIC;
    }


    broker b(t);
    // Do you want to create
    std::vector<client *> clients;
    std::vector<producer *> producers;
    unsigned int client_count, producer_count;
    unsigned int queue_count;
    std::cout << "Number of bindings keys ? ";
    std::cin >> queue_count;
    int count = 1;
    while (queue_count--) {
        std::string binding_key;
        std::cout << "Please provide key binding " << count << ": ";
        std::cin >> binding_key;
        b.register_binding(binding_key);
        count++;
    }

    std::cout << "Number of clients ? ";
    std::cin >> client_count;
    count = 1;
    while (client_count--) {
        std::string client_name;
        std::cout << "Please provide client name: ";
        std::cin >> client_name;
        std::string binding_key;
        std::cout << "Please provide client key binding: ";
        std::cin >> binding_key;
        client *c = new client{client_name, binding_key, b, logger_};
        clients.emplace_back(c);
        std::cout << std::endl;
        count++;
    }

    std::cout << "Number of producers ? ";
    std::cin >> producer_count;
    while (producer_count--) {
        std::string producer_name;
        std::cout << "Please provide producer name: ";
        std::cin >> producer_name;
        std::string topic;
        std::cout << "Please provide producer topic: ";
        std::cin >> topic;
        producer *p = new producer{producer_name, topic, b, logger_};
        producers.emplace_back(p);
    }

    for (auto ct : clients) {
        ct->start();
    }

    for (auto pr : producers) {
        pr->start();
    }


    for (auto pr : producers) {
        pr->join();
    }
    for (auto ct : clients) {
        ct->join();
    }

    return 0;
}