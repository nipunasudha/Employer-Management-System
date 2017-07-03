cmake_minimum_required(VERSION 3.7)
project(clion_employee)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h HashTable.cpp HashTable.h People.cpp People.h Utils.h ManagementSystem.cpp ManagementSystem.h)
add_executable(clion_employee ${SOURCE_FILES})