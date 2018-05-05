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

        message(string &data, string &topic);

        string get_data() const;

        string get_topic() const;

        unsigned int get_count() const;

        void increment_count();


    private:
        string data_;
        string topic_;
        unsigned int count_{};


    };
};

#endif //CODE_MESSAGE_H
