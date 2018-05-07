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

        /*
         * construct Queue
         *
         * @param: client_id: client id for which queue will be created
         */

        amqp_queue(unsigned int client_id);

        /*
        * Allow producer to push messages on to the queue in a thread safe manner.
        * @param msg: message to be pushed
        */

        void add_message(message msg);

        /*
        *
        * Read the queue in a thread safe manner.
        * Wait in case queue is empty and is active
        * @return msg: Message read in acse queue is active or Control message in case queue is no longer active
        */
        message get_message();


        /*
         * @return queue active status
         */

        bool get_queue_active_status();


        /*
         * @param i_status set queue active status to input status
         */
        void set_active_status(bool i_status);



        /*
         * @return client id with which queue is associated
         */

        unsigned int getClientId();

    private:

        //Queue where messages will be pushed
        std::queue<message> internal_queue_{};

        // client id with which queue is associated
        unsigned int client_id_;

        //queue active status
        bool queue_active_status_;

        //mutex to provide synchronised access to key
        mutex queueKey_;

        //condition variable to wait if the queue is empty.
        condition_variable queue_empty_;


    };
}


#endif //AMQP_QUEUE_H
