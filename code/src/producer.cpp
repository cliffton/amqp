//
// Created by cliffton on 5/5/18.
//

#include "producer.h"

using amqp::producer;

producer::producer(const string name) : name_{name} {

}

producer::producer(const string &name) : name_{name} {
}
