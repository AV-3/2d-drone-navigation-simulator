#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream> // For file output
#include "Drone.h"
#include "Vector2D.h"
#include "PIDController.h"

int main() {
    // --- Setup ---
    Drone drone;
    std::vector<Vector2D> waypoints = {{50.0, 50.0}, {50.0, 100.0}, {100.0, 100.0}, {100.0, 50.0}, {0.0, 0.0}};
    size_t current_waypoint_index = 0;
    
    PIDController pid_x(2.0, 0.1, 0.5);
    PIDController pid_y(2.0, 0.1, 0.5);

    const double simulation_time = 60.0;
    const double dt = 0.1;
    const double waypoint_threshold = 2.0;

    // --- File Logging Setup ---
    std::ofstream trajectory_file;
    trajectory_file.open("trajectory.csv");
    trajectory_file << "time,x,y,target_x,target_y\n"; // CSV Header

    std::cout << "--- Drone Waypoint Navigation ---" << std::endl;
    std::cout << "Simulation data will be saved to trajectory.csv" << std::endl;

    // --- Simulation Loop ---
    for (double t = 0; t < simulation_time; t += dt) {
        if (current_waypoint_index >= waypoints.size()) {
            std::cout << "All waypoints reached. Mission complete." << std::endl;
            break;
        }

        Vector2D target_position = waypoints[current_waypoint_index];
        Vector2D current_pos = drone.getPosition();

        // Log data to file
        trajectory_file << t << "," << current_pos.x << "," << current_pos.y << ","
                        << target_position.x << "," << target_position.y << "\n";

        if (current_pos.distanceTo(target_position) < waypoint_threshold) {
            current_waypoint_index++;
            continue;
        }
        
        double force_x = pid_x.calculate(target_position.x, current_pos.x, dt);
        double force_y = pid_y.calculate(target_position.y, current_pos.y, dt);
        
        drone.update({force_x, force_y}, dt);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(dt * 1000)));
    }

    trajectory_file.close();
    std::cout << "Simulation finished. Trajectory saved to trajectory.csv" << std::endl;
    return 0;
}