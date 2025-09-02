#pragma once

#include "pros/rtos.hpp"
#include "pros/misc.hpp"

class DoInker {
  public:
    DoInker();
    void toggle();
    void run(pros::controller_digital_e_t button);
    void activate();
    void deactivate();
    bool getState() const;
};