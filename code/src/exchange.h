//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_EXCHANGE_H
#define CODE_EXCHANGE_H

#include <map>
#include "queue.h"
#include "message.h"
#include "client.h"

using amqp::amqp_queue;
using amqp::message;

namespace amqp {
    class exchange {
    public:
        enum type {
            DIRECT,
            FAN_OUT,
            TOPIC
        };

        /**
         * Constructor takes
         * exchange type as input.
         * @param ex_type
         */
        exchange(type etype);

        /**
         * Binds a queue to the give
         * binding key.
         * @param q
         * @param routing_key
         */
        void bind(const std::string &routing_key);

        void process_message(message msg);

        /**
         * Send message to all queues
         * @param msg
         */
        void fanout(message msg) {
            for (auto b : bindings_) {
                for (auto q : b.second) {
                    q.add_message(msg);
                }
            }
        }

        /**
         * Send message to same routing keys.
         * @param msg
         */
        void direct(message msg) {
            auto queues = bindings_.find(msg.get_topic());
            if (queues != bindings_.end()) {
                for (auto q: queues->second) {
                    q.add_message(msg);
                }
            }
        }

        void topic(message msg) {

        }

        void bind_client(client c, const string &binding_key);

    private:
        type type_;
        std::map<std::string, std::vector<amqp_queue>> bindings_;
    };
}

#endif //CODE_EXCHANGE_H
