cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(life)

add_subdirectory(googletest)
add_subdirectory(test)
add_subdirectory(mock)

set(APP_SOURCE
	unit.cpp unit.h)


add_executable(${PROJECT_NAME}
	main.cpp
	${APP_SOURCE}
	)
