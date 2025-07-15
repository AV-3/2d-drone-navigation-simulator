#include "Drone.h"

Drone::Drone() {
    position = {0.0, 0.0};
    velocity = {0.0, 0.0};
    mass = 1.0; // kg
    drag_coefficient = 0.1; 
}

void Drone::update(Vector2D force, double dt) {
    // Calculate drag force (acts opposite to velocity)
    Vector2D drag_force;
    drag_force.x = -drag_coefficient * velocity.x;
    drag_force.y = -drag_coefficient * velocity.y;

    // Calculate net force
    Vector2D net_force;
    net_force.x = force.x + drag_force.x;
    net_force.y = force.y + drag_force.y;

    // Calculate acceleration (F=ma -> a=F/m)
    Vector2D acceleration;
    acceleration.x = net_force.x / mass;
    acceleration.y = net_force.y / mass;

    // Update velocity and position
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
}

Vector2D Drone::getPosition() const {
    return position;
}
