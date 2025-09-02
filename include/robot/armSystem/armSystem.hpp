#pragma once

#include "pros/rtos.hpp"
#include "pros/misc.hpp"
#include "armMotor.hpp"
#include "armPiston.hpp"

extern Arm armM;
// extern ArmPiston armP;

class ArmSystem {
  public:
    ArmSystem();
    void readyToScore(pros::controller_digital_e_t button, int armVelocity);
    void goToPosition(pros::controller_digital_e_t button, int armVelocity);
};