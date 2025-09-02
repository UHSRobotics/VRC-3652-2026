#pragma once

#include "pros/rtos.hpp"
#include "pros/misc.hpp"

class Clamp {
  public:
    Clamp();
    void toggle();
    void run(pros::controller_digital_e_t button);
    void clampStake();
    void deClamp();
    bool getState() const;
};