#pragma once

#include "pros/rtos.hpp"
#include "pros/misc.hpp"

class Wing {
  public:
    Wing();
    void toggle();
    void run(pros::controller_digital_e_t button);
    bool getState() const;
};