#include "../../../include/robot/armSystem/armMotor.hpp"
#include "../../../include/globals.hpp"

armState Arm::currentArmState = armState::IDLE;

Arm::Arm() {}

void Arm::moveForward() {
  armMotor.move(127);
}

void Arm::moveBackward() {
  armMotor.move(-127);
}

void Arm::stop() {
  armMotor.move(0);
}

bool Arm::isActive() const {
  return isArmActive;
}

void Arm::activate() {
  isArmActive = true;
  moveForward();
}

void Arm::deactivate() {
  isArmActive = false;
  stop();
}

void Arm::holdControl(pros::controller_digital_e_t button) {
  if (controller.get_digital(button)) {
    moveForward();
    isArmActive = true;
  } else if (controller.get_digital(button)) {
    moveBackward();
    isArmActive = true;
  } else {
    deactivate();
    isArmActive = false;
  }
}

void Arm::moveByAmount(int amount, int armVelocity) {
    armMotor.move_relative(amount, armVelocity);
    currentArmState = armState::MANUAL_CONTROL;
}

void Arm::controlByAmount(pros::controller_digital_e_t button, int amount, int armVelocity) {
  if (controller.get_digital(button)) {
    moveByAmount(amount, armVelocity);
    currentArmState = armState::MANUAL_CONTROL;
  }
}

void Arm::moveMacro(armState state, int armVelocity) {
  switch (state)
  {
  case armState::IDLE:
    armMotor.move_absolute((double) armState::IDLE, armVelocity);
    currentArmState = armState::IDLE;
    break;

  case armState::PICKUP:
    armMotor.move_absolute((double) armState::PICKUP, armVelocity);
    currentArmState = armState::PICKUP;
    break;

  case armState::READY:
    armMotor.move_absolute((double) armState::READY, armVelocity);
    currentArmState = armState::READY;
  }
}