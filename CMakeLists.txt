cmake_minimum_required(VERSION 3.29)
project(flybird)

set(CMAKE_CXX_STANDARD 14)

add_executable(flybird
        include/Bird.h
        Bird.cpp
        Tool.cpp
        include/Pipe.h
        pipe.cpp
        include/Game.h
        Game.cpp
        include/Tool.h
        main.cpp
)
