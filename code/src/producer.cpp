#include "producer.h"
#include <sstream>
#include "logger.h"

using amqp::producer;


unsigned int producer::next_id = 1;


/*
* Construct producer.
*
* @param   i_name: name of the producer
* @param   i_topic: topic based on which messages will be routed
* @param   i_broker: Reference to broker
* @param   i_logger: Reference to the thread safe logger
*/

producer::producer(string& i_name, string& i_topic, broker& i_broker,logger& i_logger) : name_{i_name},
                                                                        topic_{i_topic},
                                                                        broker_{i_broker},
                                                                        logger_{i_logger} {

    id_ = next_id;
    next_id++;
    std::cout<<"Producer "<< id_<<" has been created.";

}

/*
 * push messages for some time.
 * Notify broker that there are no more messages and exit.
 */

void producer::run() {

    long start = std::chrono::system_clock::now().time_since_epoch().count();
    long end = 0;
    int dataIndex = 0;
    do {
        std::stringstream data;
        data<<"Producer ID: "<<id_<<" Topic: "<<topic_<<" Message: "<<dataIndex++;
        logger_.log(std::string("PD: ") + data.str());
        message msg = message(data.str(), topic_);
        broker_.publish(msg);
        end = std::chrono::system_clock::now().time_since_epoch().count();

    } while((end - start) < 1000);
    broker_.endBinding(topic_);
}