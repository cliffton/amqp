//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_CLIENT_H
#define CODE_CLIENT_H

#include <string>
#include <thread>

using std::string;
using std::thread;

namespace amqp {
    class client {

    public:
        static unsigned int next_id;

        client(const string &name, const string &binding_key);

        ~client();

        unsigned int get_id();

        // Establish connection to queue
        // Consume messages from queue.
        void consume();

        void run();

        void start();

        void join();

        void stop();

        bool is_running = true;

    private:
        unsigned int id_;
        string name_;
        string binding_key_;
        thread thread_;

    };
}

#endif //CODE_CLIENT_H
