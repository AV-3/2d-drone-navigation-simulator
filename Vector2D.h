#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>

struct Vector2D {
    double x = 0.0;
    double y = 0.0;

    // Helper function to calculate distance to another point
    double distanceTo(const Vector2D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

#endif
