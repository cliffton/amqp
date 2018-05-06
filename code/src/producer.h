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
        static unsigned int next_id;


        producer(string& i_name, string& i_topic, broker& i_broker,logger& i_logger);

        unsigned int get_id();

        void run();

    private:
        unsigned int id_;
        string name_;
        broker& broker_;
        logger& logger_;
        string topic_;


    };
}

#endif //CODE_PRODUCER_H
