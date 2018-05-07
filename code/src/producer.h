#ifndef CODE_PRODUCER_H
#define CODE_PRODUCER_H

#include <string>
#include "message.h"
#include "broker.h"
#include "logger.h"
#include "my_thread.h"


using std::string;
using amqp::message;
using amqp::broker;

namespace amqp {

    /**
     * This is the process that produces
     * the messages and publishes the messages to the broker.
     * The instances of this class should run as separate
     * thread publishing messages to the broker.
     *
     * @authors Manpreet Kaur, Cliffton Fernandes
     *
     */
    class producer: public my_thread{

    public:

        /*
         * static data member to assign unique id's to all the producers
         */
        static unsigned int next_id;


        /*
         * Construct producer.
         *
         * @param   i_name: name of the producer
         * @param   i_topic: topic based on which messages will be routed
         * @param   i_broker: Reference to broker
         * @param   i_logger: Reference to the thread safe logger
         */
        producer(string& i_name, string& i_topic, broker& i_broker,logger& i_logger);

        /*
         * @return unique id for the client.
         */

        unsigned int get_id();

        /*
         * push messages for some time.
         * Notify broker that there are no more messages and exit.
         */
        void run();

    private:

        //unique Id for the producer
        unsigned int id_;

        //name for the producer
        string name_;

        //Reference to broker
        broker& broker_;

        //Reference to Thread safe logger.
        logger& logger_;

        //topic based on which messages will be routed
        string topic_;


    };
}

#endif //CODE_PRODUCER_H
