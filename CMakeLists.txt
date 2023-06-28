cmake_minimum_required(VERSION 3.14)
project(The_Chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Figures.cpp inc/Figures.hpp src/Board.cpp inc/Board.hpp src/game.cpp inc/game.hpp src/log.cpp inc/log.hpp src/Board.cpp)
add_executable(The_Chess ${SOURCE_FILES})
include_directories(/ext/SFML/include/)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(The_Chess sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
