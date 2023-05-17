cmake_minimum_required(VERSION 3.23)
project(map_projet_algo C)

set(CMAKE_C_STANDARD 99)

add_executable(map_projet_algo main.c)
target_link_libraries(map_projet_algo -lmingw32 -lalleg44)
