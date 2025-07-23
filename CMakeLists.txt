cmake_minimum_required(VERSION 3.10)
project(2d-drone-navigation-simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

add_executable(drone_sim main.cpp Drone.cpp PIDController.cpp)

set(VENV_PYTHON "${CMAKE_SOURCE_DIR}/.venv/bin/python")

add_custom_target(run_all
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/drone_sim
    COMMAND ${VENV_PYTHON} ${CMAKE_SOURCE_DIR}/plot_trajectory.py
    DEPENDS drone_sim
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running drone_sim and then plot_trajectory.py with venv python"
)


