#ifndef CODE_CLIENT_H
#define CODE_CLIENT_H

#include <string>
#include "my_thread.h"
#include "queue.h"
#include "logger.h"


namespace amqp{
    class broker;
}

using std::string;
using std::thread;

namespace amqp {

    /**
     * This class simulates the consumer.
     * The consumer consumes the messages from the queues.
     * Each instance is this class should be run
     * as separate threads.
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class client : public my_thread {

    public:
        /*
         * static data member to assign unique id's to all the clients
         */
        static unsigned int next_id;


        /*
         * Construct client.
         *
         * @param   i_name: name of the client
         * @param   i_bindingKey: binding key based on which messages will be routed
         * @param   i_broker: Reference to broker
         * @param   i_logger: Reference to the thread safe logger
         */

        client(string i_name, string i_bindingKey,broker& i_broker, logger& i_logger);




        /*
         * @return unique id for the client.
         */

        unsigned int get_id();

        /*
         * Consume all the Messages from the linked queue and exit.
         * @return true if the read Message is DATA message and false if the read Message is CONTROL
         */

        bool consume();

        /*
         * Read all the message from the queue and exit when consume receives CONTROL message.
         */

        void run();


    private:

        //unique Id for the client
        unsigned int id_;

        //name for the client
        string name_;

        //binding key based on which messages will be routed
        string binding_key_;

        //handle for subscribed queue
        std::shared_ptr<amqp_queue> client_queue_;


        //Reference to broker
        broker& broker_;

        //Reference to Thread safe logger.
        logger& logger_;


    };
}

#endif //CODE_CLIENT_H
