cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lncurses")

set(SOURCE_FILES main.cpp Matrix.cpp Matrix.h Pawn.cpp Pawn.h)
add_executable(untitled ${SOURCE_FILES})
target_link_libraries(untitled curses)