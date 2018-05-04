//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_EXCHANGE_H
#define CODE_EXCHANGE_H

namespace amqp {
    class exchange {

        enum type {
            DIRECT,
            FAN_OUT,
            TOPIC
        };

    private:
        type type_;
    };
}

#endif //CODE_EXCHANGE_H
