cmake_minimum_required(VERSION 3.9)
project(AMQP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Weffc++ -pedantic -pthread -g")

set(AMQP_SOURCE_FILES
        src/queue.cpp
        src/exchange.cpp
        src/broker.cpp
        main.cpp)


add_executable(AMQP ${AMQP_SOURCE_FILES})