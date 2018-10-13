cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(life)

enable_testing()

include_directories(rpi-rgb-led-matrix/include)

add_subdirectory(googletest)
add_subdirectory(test)
add_subdirectory(mock)
