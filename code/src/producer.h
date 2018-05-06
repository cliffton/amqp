//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_PRODUCER_H
#define CODE_PRODUCER_H

#include <string>
#include "message.h"
#include "broker.h"


using std::string;
using amqp::message;
using amqp::broker;

namespace amqp {
    class producer {

    public:
        static unsigned int next_id;

        producer(const string name, broker b);

        producer(const string &name, broker b);

        unsigned int get_id();

        // Establish connection to queue
        // Consume messages from queue.
        void connect();

        void consume();

        void run();

    private:
        unsigned int id_;
        string name_;
        broker broker_;

    };
}

#endif //CODE_PRODUCER_H
