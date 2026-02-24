#pragma once

#include "pros/optical.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"

class Intake {
  public:
    Intake();
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void holdControl(pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton, pros::controller_digital_e_t middleGoalButton, pros::controller_digital_e_t longGoalButton);
    void stop();
    bool isActive() const;
    void activate();
    void deactivate();
    
    void trapdoor_pos(int state);
};