#ifndef DRONE_H
#define DRONE_H

#include "Vector2D.h"

class Drone {
public:
    Drone();

    // Updates the drone's state based on applied force and time step
    void update(Vector2D force, double dt);

    Vector2D getPosition() const;

private:
    Vector2D position;
    Vector2D velocity;
    double mass;
    double drag_coefficient;
};

#endif