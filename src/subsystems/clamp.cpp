#include "../../include/robot/clamp.hpp"
#include "../../include/globals.hpp"

Clamp::Clamp() {}

void Clamp::toggle() {
  isClamped = !isClamped;
  mogoClamp.set_value(isClamped ? 1 : 0);
}

void Clamp::clampStake() {
  isClamped = true;
  mogoClamp.set_value(1);
  pros::delay(500);
}

void Clamp::deClamp() {
  isClamped = false;
  mogoClamp.set_value(0);
  pros::delay(500);
}

bool Clamp::getState() const {
  return isClamped;
}

void Clamp::run(pros::controller_digital_e_t button) {
  if (controller.get_digital_new_press(button)) {
    toggle();
  }
}

