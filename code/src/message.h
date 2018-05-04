//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_MESSAGE_H
#define CODE_MESSAGE_H

#include <string>

using std::string;

namespace amqp {
    class message {
    public:

        message(string &data, string &topic) {
            data_ = data;
            topic_ = topic;
        }

        string get_data() const {
            return data_;
        }

        string get_topic() const {
            return topic_;
        }

    private:
        string data_;
        string topic_;


    };
};

#endif //CODE_MESSAGE_H
