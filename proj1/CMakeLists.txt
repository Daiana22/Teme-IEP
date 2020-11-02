cmake_minimum_required(VERSION 3.2)

project(proj1)
set(CMAKE_CXX_STANDARD 14)	 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_executable(app main.cpp)

install(TARGETS app DESTINATION bin)
