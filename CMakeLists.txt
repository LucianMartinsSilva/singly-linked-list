cmake_minimum_required(VERSION 3.28)
project(LinkedList C)

set(CMAKE_C_STANDARD 23)

add_executable(LinkedList main.c
        SinglyLinkedList.h
        SinglyLinkedList.c
)
