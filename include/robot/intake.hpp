#pragma once

#include "pros/optical.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"

class Intake {
  public:
    Intake();
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void holdControl(pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton);
    void toggleControl(pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton);
    void stop();
    bool isActive() const;
    void activate();
    void deactivate();
};