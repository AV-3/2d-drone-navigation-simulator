#include "PIDController.h"

PIDController::PIDController(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->prev_error = 0.0;
    this->integral = 0.0;
}

double PIDController::calculate(double setpoint, double current_value, double dt) {
    double error = setpoint - current_value;

    // Proportional term
    double p_out = Kp * error;

    // Integral term
    integral += error * dt;
    double i_out = Ki * integral;

    // Derivative term
    double derivative = (error - prev_error) / dt;
    double d_out = Kd * derivative;

    // Total output
    double output = p_out + i_out + d_out;

    // Save current error for next iteration
    prev_error = error;

    return output;
}