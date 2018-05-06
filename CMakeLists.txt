cmake_minimum_required(VERSION 3.9)
project(AMQP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Weffc++ -pedantic -pthread -g")

set(AMQP_SOURCE_FILES
        code/src/message.cpp
        code/src/queue.cpp
        code/src/exchange.cpp
        code/src/broker.cpp
        code/src/client.cpp
        code/src/producer.cpp
        code/src/logger.cpp
        code/src/my_thread.cpp
        code/main.cpp)


add_executable(AMQP ${AMQP_SOURCE_FILES})