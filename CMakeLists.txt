cmake_minimum_required(VERSION 3.24)
project(2048)

set(CMAKE_CXX_STANDARD 17)

add_executable(2048
        Board.cpp
        Board.h
        Colors.cpp
        Colors.h
        ColorsEnum.h
        KeyEvents.cpp
        KeyEvents.h
        main2048.cpp
        P2048.cpp
        P2048.h
        Tile.cpp
        Tile.h
        Position.cpp
        Position.h)

target_link_libraries(2048 sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)