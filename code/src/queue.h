#ifndef AMQP_QUEUE_H
#define AMQP_QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>
#include "message.h"

using amqp::message;
using std::lock_guard;
using std::mutex;
using std::condition_variable;

namespace amqp {

    /**
     * Stores the messages forwarded by the exchange.
     * The consumers subscribe to the queues and
     * read the messages from the respective queues.
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class amqp_queue {

    public:


        amqp_queue(unsigned int client_id);

        void add_message(message msg);

        message get_message();

        bool get_queue_active_status();




        unsigned int getClientId();

    private:

        std::queue<message> internal_queue_{};
        unsigned int consumers_{};
        unsigned int client_id_;
        bool queue_active_status_;
        mutex queueKey_;
        condition_variable queue_empty_;


    };
}


#endif //AMQP_QUEUE_H
