//
// Created by cliffton on 4/9/18.
//

#ifndef CODE_MESSAGE_H
#define CODE_MESSAGE_H

#include <string>

using std::string;

namespace amqp {


    enum MessageType {
        DATA,
        CONTROL
    };

    class message {


    public:
        message(string data, string topic, MessageType type);

        message(string data, string topic);

        string get_data() const;

        string get_topic() const;

        unsigned int get_count() const;

        void increment_count();

        void setMessageType();

        MessageType getMessageType();


    private:
        string data_;
        string topic_;
        unsigned int count_{};

        MessageType type_;


    };
};

#endif //CODE_MESSAGE_H
