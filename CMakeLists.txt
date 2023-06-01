cmake_minimum_required(VERSION 3.0)

project(libutil)

add_executable(libutil main.cpp)

install(TARGETS libutil RUNTIME DESTINATION bin)
