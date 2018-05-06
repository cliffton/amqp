//
// Created by cliffton on 5/5/18.
//

#include "queue.h"

using amqp::amqp_queue;


amqp_queue::amqp_queue(unsigned int client_id) : client_id_{client_id},queue_active_status_{true} {
    std::cout << "Created AMQP Queue!" << std::endl;
}


void amqp_queue::add_message(message msg) {

    {
        lock_guard<mutex> queue_lock_guard{queueKey_};
        internal_queue_.push(msg);
    }
    queue_empty_.notify_all();
}


message amqp_queue::get_message() {

    std::unique_lock<mutex> queue_lock_guard{queueKey_};

    queue_empty_.wait(queue_lock_guard,[this] { return (!internal_queue_.empty() || !queue_active_status_); });

    if(!internal_queue_.empty()) {
        message msg = internal_queue_.front();
        internal_queue_.pop();
        return msg;
    }
    //NO More data for this  queue. Producer has finished publishing data.
    if(!queue_active_status_) {

        //Construct a control message to inform client that
        //producer has finished producing data
        string messageSrtring("NO More Data");
        string topic = "";
        message msg ( messageSrtring,topic,MessageType::CONTROL);
        return msg;
    }


}

unsigned int amqp::amqp_queue::getClientId() {
    return client_id_;
}
