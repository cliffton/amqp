//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_CLIENT_H
#define CODE_CLIENT_H

#include <string>
#include "my_thread.h"
#include "queue.h"
#include "broker.h"
#include "logger.h"


using std::string;
using std::thread;

namespace amqp {
    class client : my_thread {

    public:
        static unsigned int next_id;

        client(string i_name, string i_bindingKey,broker& i_broker, logger& i_logger);

        ~client();

        unsigned int get_id();

        // Establish connection to queue
        // Consume messages from queue.
        void consume();

        void run();



    private:
        unsigned int id_;
        string name_;
        string binding_key_;
        std::shared_ptr<amqp_queue> client_queue_;
        broker& broker_;
        logger& logger_;


    };
}

#endif //CODE_CLIENT_H
