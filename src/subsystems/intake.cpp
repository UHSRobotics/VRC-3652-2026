#include "../../include/robot/intake.hpp"
#include "../../include/globals.hpp"

Intake::Intake() {}

void Intake::moveForward(int velocity) {
  intakeMotors.move(velocity);
}

void Intake::moveBackward(int velocity) {
  intakeMotors.move(-velocity);
}

void Intake::stop() {
  intakeMotors.move(0);
}

bool Intake::isActive() const {
  return isIntakeActive;
}

void Intake::activate() {
  isIntakeActive = true;
  moveForward(127);
}

void Intake::deactivate() {
  isIntakeActive = false;
  stop();
}

void Intake::holdControl(pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton) {
  if (controller.get_digital(intakeButton)) {
    moveForward(127);
    isIntakeActive = true;
  } else if (controller.get_digital(outtakeButton)) {
    moveBackward(127);
    isIntakeActive = true;
  } else {
    deactivate();
    isIntakeActive = false;
  }
}

void Intake::toggleControl(pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton) {
  if (controller.get_digital(intakeButton) && controller.get_digital(outtakeButton)) {
    deactivate();
    isIntakeActive = false;
  } else if (controller.get_digital(intakeButton)) {
    controller.print(1, 1, "Intake");
    moveForward(127);
    isIntakeActive = true;
  } else if (controller.get_digital(outtakeButton)) {
    controller.print(1, 1, "Outtake");
    moveBackward(127);
    isIntakeActive = true;
  }
}