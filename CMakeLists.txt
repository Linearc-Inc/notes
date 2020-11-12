project(Note C CXX)
cmake_minimum_required(VERSION 3.3.2)

include(cmake/App.cmake)

set(SOURCES "src/note.h"
            "src/note.cpp"
            "src/main.cpp")

add_app("${SOURCES}")