//
// Created by cliffton on 5/5/18.
//

#ifndef AMQP_QUEUE_H
#define AMQP_QUEUE_H

#include <queue>

namespace amqp {

    class queue {
    public:

    private:

//        std::queue internal_queue;
        unsigned int consumers_{};
    };
}


#endif //AMQP_QUEUE_H
