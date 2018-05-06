//
// Created by cliffton on 5/5/18.
//

#include "producer.h"
#include <sstream>
#include "logger.h"

using amqp::producer;


unsigned int producer::next_id = 1;

producer::producer(string& i_name, string& i_topic, broker& i_broker,logger& i_logger) : name_{i_name},
                                                                        topic_{i_topic},
                                                                        broker_{i_broker},
                                                                        logger_{i_logger} {

    id_ = next_id;
    next_id++;
    std::cout<<"Producer "<< id_<<" has been created.";

}



void producer::run() {

    auto start = std::chrono::system_clock::now();
    auto end ;
    int dataIndex = 0;
    do {
        std::stringstream data;
        data<<"Producer ID: "<<id_<<" Topic: "<<topic_<<" Message: "<<dataIndex++;
        logger_.log(std::string("PD: ") + data.str());
        message msg = message(data.str(), topic_);
        broker_.publish(msg);
        end = std::chrono::system_clock::now();

    } while(end - start < 10000);
}