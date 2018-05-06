//
// Created by cliffton on 5/5/18.
//

#include "producer.h"

using amqp::producer;

producer::producer(const string name, broker b) : name_{name}, broker_{b} {

}

producer::producer(const string &name, broker b) : name_{name}, broker_{b} {
}


void producer::run() {
    while (broker::is_running) {
        message msg = message("data", "x.x");
        broker_.publish(msg);
    }
}