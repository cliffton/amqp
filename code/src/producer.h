//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_PRODUCER_H
#define CODE_PRODUCER_H

namespace amqp {

    class producer {

        // Establish connection to broker
        // Send message to broker.

        /**
         * Connect to server/broker
         */
        void connect();

        /**
         * Send message to broker/server.
         */
        void send_message();

    };
}

#endif //CODE_PRODUCER_H
