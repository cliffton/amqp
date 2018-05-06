//
// Created by cliffton on 5/5/18.
//

#ifndef AMQP_QUEUE_H
#define AMQP_QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>
#include "message.h"

using amqp::message;
using std::lock_guard;
using std::mutex;

namespace amqp {

    class amqp_queue {
    public:

        amqp_queue();

        void add_message(message msg);

        message get_message();

    private:

        std::queue<message> internal_queue_{};
        unsigned int consumers_{};
    };
}


#endif //AMQP_QUEUE_H
