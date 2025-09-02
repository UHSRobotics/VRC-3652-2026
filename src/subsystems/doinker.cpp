#include "../../include/robot/doinker.hpp"
#include "../../include/globals.hpp"

DoInker::DoInker() {}

void DoInker::toggle() {
  isDoinkerDown = !isDoinkerDown;
  doInker.set_value(isDoinkerDown ? 1 : 0);
}

void DoInker::activate() {
  isDoinkerDown = true;
  doInker.set_value(1);
  pros::delay(500);
}

void DoInker::deactivate() {
  isDoinkerDown = false;
  doInker.set_value(0);
  pros::delay(500);
}

bool DoInker::getState() const {
  return isDoinkerDown;
}

void DoInker::run(pros::controller_digital_e_t button) {
  if (controller.get_digital_new_press(button)) {
    toggle();
  }
}