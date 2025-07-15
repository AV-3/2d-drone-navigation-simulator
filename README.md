# 2d-drone-navigation-simulator
2D Drone Waypoint Navigation Simulator
This project is a C++ application that simulates the Guidance, Navigation, and Control (GNC) loop for a 2D quadcopter drone. The goal is to autonomously guide the drone through a series of predefined waypoints while subject to simplified physics, including mass and drag.

The project is built entirely from scratch to demonstrate a foundational understanding of GNC principles and C++ software development.

Core Concepts Demonstrated
Guidance: The system uses a std::vector of waypoints to define the drone's mission path. The guidance logic in main.cpp determines the current target and switches to the next waypoint once the drone is within a specified threshold.

Navigation: In this simulation, navigation is simplified. The drone's state (position and velocity) is known perfectly at each time step. The core challenge is controlling this state.

Control: The system uses two independent PID (Proportional-Integral-Derivative) controllers—one for the X-axis and one for the Y-axis. These controllers calculate the necessary forces to apply to the drone to minimize the error between its current position and the target waypoint.

Technical Stack
Language: C++ (using the C++17 standard)

Build System: CMake

Analysis & Visualization: Python with pandas and matplotlib

How to Build and Run
Prerequisites
A C++ compiler (g++ on Linux, MSVC on Windows)

CMake (version 3.10 or higher)

Python 3 and the pip package manager

Python libraries: pip install pandas matplotlib

Build Instructions
Clone the repository.

Create a build directory inside the project folder.

Navigate into the build directory.

Run cmake .. to configure the project.

Run make (on Linux) or build the solution in Visual Studio (on Windows).

Running the Simulation
Execute the compiled program (drone_sim or drone_sim.exe). This will run the C++ simulation and generate a trajectory.csv file.

Run the Python visualization script to see the results: py plot_trajectory.py (Make sure your terminal is in the same directory as the plot_trajectory.py file!)

Results and Analysis
The primary output of this project is the analysis of the drone's flight path. The PID controller's gains (Kp, Ki, Kd) were tuned to provide a stable response, minimizing overshoot while ensuring a quick convergence to the target.

2D Trajectory Plot
This plot shows the drone's actual flight path in blue as it navigates between the green waypoints. This visualizes the overall success of the GNC system.

![alt text](<Screenshot 2025-07-14 224314.png>)

Position vs. Time Plots
These plots show the drone's X and Y positions over time compared to the target positions. They are crucial for analyzing the controller's performance, showing how quickly the drone settles at each waypoint and the amount of overshoot.

![alt text](image.png)