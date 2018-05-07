#ifndef CODE_EXCHANGE_H
#define CODE_EXCHANGE_H

#include <map>
#include "queue.h"
#include "message.h"
#include "client.h"

using amqp::amqp_queue;
using amqp::message;

namespace amqp {

    /**
     * The exchange is responsible for sorting the messages into
     * different queues depending on the routing key of the message.
     * There are 3 types of exchanges:
     *  - Fanout
     *  - Direct
     *  - Topic
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class exchange {
    public:

        /*
         * Echange Type
         *  - Fanout
         *  - Direct
         *  - Topic
         *
         */
        enum type {
            DIRECT,
            FAN_OUT,
            TOPIC
        };

        /**
         *
         * Construct exchange with input type
         * @param ex_type
         */
        exchange(type etype);

        /**
         * Binds a queue to the given binding key.
         * @param routing_key: Messages will be routed to the queue based on teh binding key
         */
        void bind(const std::string &routing_key);

        /**
         * Push the message to appropriate queue.
         */

        void process_message(message msg);

        /**
         * Send message to all queues
         * @param msg
         */
        void fanout(message msg);

        /**
         * Send message to the queue with exact same routing keys.
         * @param msg
         */
        void direct(message msg);


        /**
         * Send Message to all the the queues for which  binding key matches input message topic key.
         *
         * For example: Message of type: Fruit will be sent to queues with binding key Fruit.Orange, Fruit.Apple, Fruit
         * but  not to any other queue which does not have key that matches input message type pattern.
         *
         * @param msg: Message to be sent.
         */
        void topic(message msg);


        /**
         * Create new queue for the client and link the queue to binding queue list
         *
         * @param i_client: Client that will consume messages from the queue
         * @param i_binding_key: binding Key using which messages will be routed.
         * @return return handle to the amqp queue.
         */
        std::shared_ptr<amqp_queue> bind_client(client &i_client, const string &i_binding_key);

        /**
         * delete all the queues linked to the queue
         */

        void endSession();

        /*
         * End Binding for the input binding key
         * @param i_bindingKey: binding key for the producer for which there exist no more data
         */
        void endBinding(string i_bindingKey);

    private:

        //Define exchange type
        type type_;

        //defines the binding key and corresponding queues.
        std::map<std::string, std::vector<std::shared_ptr<amqp_queue> > > bindings_;
    };
}

#endif //CODE_EXCHANGE_H
