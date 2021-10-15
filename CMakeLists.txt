cmake_minimum_required(VERSION 3.10)

project(AdventureGame)

find_package(SFML 2.5 COMPONENTS graphics audio window system network REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /media/jonathan/2TB\ Storage\ and\ Game\ Drive/Jon/Programming/AdventureGamePrototype)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Main.out main.cpp battle/battle.cpp battle/battleAnimation.cpp)

target_link_libraries(Main.out sfml-graphics sfml-audio)

