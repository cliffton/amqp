//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_CLIENT_H
#define CODE_CLIENT_H

#include <string>

using std::string;

namespace amqp {
    class client {

    public:
        static unsigned int next_id;

        client(const string &name, const string &binding_key);

        unsigned int get_id();

        // Establish connection to queue
        // Consume messages from queue.
        void connect();

        void consume();

    private:
        unsigned int id_;
        string name_;
        string binding_key_;

    };
}

#endif //CODE_CLIENT_H
