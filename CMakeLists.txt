# Title: Collision Pi
# Author: rdvdev2 (rdvdev2@gmail.com)
# Description: Calculate Pi with the extremely inefficient method of counting perfectly elastic collisions

cmake_minimum_required(VERSION 3.15)
project(collision_pi)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(collision_pi main.cpp)