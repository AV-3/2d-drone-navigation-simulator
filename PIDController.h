#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PIDController {
public:
    PIDController(double Kp, double Ki, double Kd);

    // Calculates the control output
    double calculate(double setpoint, double current_value, double dt);

private:
    double Kp;
    double Ki;
    double Kd;
    double prev_error;
    double integral;
};

#endif
