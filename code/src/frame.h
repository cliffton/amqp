//
// Created by cliffton on 4/10/18.
//

#ifndef CODE_FRAME_H
#define CODE_FRAME_H

#include <string>

namespace amqp {

    enum frame_type {
        protocol,
        method,
        content,
        body,
        heartbeat
    };

    class frame {

    public:
        frame(frame_type type, unsigned int channel) :
                type_{type},
                channel_{channel} {
        };

        void set_payload(std::string &payload) {
            payload = payload;
        }

    private:
        frame_type type_;
        unsigned int channel_;
        //unsigned int size_;
        std::string payload_;
    };
}

#endif //CODE_FRAME_H
