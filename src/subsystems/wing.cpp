#include "../../include/robot/wing.hpp"
#include "../../include/globals.hpp"

Wing::Wing() {}

void Wing::toggle() {
  descore_state = !descore_state;
  descore.set_value(descore_state ? 1 : 0);
}

bool Wing::getState() const {
  return descore_state;
}

void Wing::run(pros::controller_digital_e_t button) {
  if (controller.get_digital_new_press(button)) {
    toggle();
  }
}

