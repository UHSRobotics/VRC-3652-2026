#pragma once

#include "pros/misc.hpp"

enum class armState {
  PICKUP,
  IDLE = 650,
  READY = 1500,
  MANUAL_CONTROL
};

class Arm {
  public:
    static armState currentArmState;
    Arm();
    void moveForward();
    void moveBackward();
    void stop();
    bool isActive() const;
    void activate();
    void deactivate();
    void moveByAmount(int amount, int armVelocity);
    void moveMacro(armState state, int armVelocity);
    void controlByAmount(pros::controller_digital_e_t button, int amount, int armVelocity);
    void holdControl(pros::controller_digital_e_t button);
};