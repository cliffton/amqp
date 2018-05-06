//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_PRODUCER_H
#define CODE_PRODUCER_H

#include <string>

using std::string;

namespace amqp {
    class producer {

    public:
        static unsigned int next_id;

        producer(const string name);

        producer(const string &name);

        unsigned int get_id();

        // Establish connection to queue
        // Consume messages from queue.
        void connect();

        void consume();

        void run();

    private:
        unsigned int id_;
        string name_;

    };
}

#endif //CODE_PRODUCER_H
