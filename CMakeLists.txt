cmake_minimum_required(VERSION 3.10)
project(2d-drone-navigation-simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(drone_sim main.cpp Drone.cpp PIDController.cpp)