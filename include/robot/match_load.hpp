#pragma once

#include "pros/rtos.hpp"
#include "pros/misc.hpp"

class Match_load {
  public:
    Match_load();
    void toggle();
    void run(pros::controller_digital_e_t button);
    bool getState() const;
};