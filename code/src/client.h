//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_CLIENT_H
#define CODE_CLIENT_H

namespace amqp {
    class client {

        // Establish connection to queue
        // Consume messages from queue.
        void connect();

        void consume();

    };
}

#endif //CODE_CLIENT_H
