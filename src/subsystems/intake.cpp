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

void Intake::trapdoor_pos(int state){ // Change the 2 trapdoor piston based on long/middle goal or intake
    switch(state){
        case 0:
            trapdoorb_state = true;
            trapdoorm_state = false;
            break;
        case 1:
            trapdoorb_state = true;
            trapdoorm_state = true;
            break;
        case 2:
            trapdoorb_state = false;
            trapdoorm_state = false; 
            break;
        default:
            trapdoorb_state = false;
            trapdoorm_state = false;
            break;
    }
    trapdoor_b.set_value(trapdoorb_state);
    trapdoor_m.set_value(trapdoorm_state);
    pros::delay(10);
}

void Intake::holdControl(pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton, pros::controller_digital_e_t middleGoalButton, pros::controller_digital_e_t longGoalButton) {
  if (controller.get_digital(intakeButton)) {
    intake_state = 0;
    moveForward(127);
    isIntakeActive = true;
  } 
  else if (controller.get_digital(outtakeButton)) {
    intake_state = 0;
    moveBackward(127);
    isIntakeActive = true;
  } 
  else if (controller.get_digital(middleGoalButton)) {
    intake_state = 1;
    moveForward(127);
    isIntakeActive = true;
  } 
  else if (controller.get_digital(longGoalButton)) {
    intake_state = 2;
    moveForward(127);
    isIntakeActive = true;
  } 
  else {
    deactivate();
    isIntakeActive = false;
  }
  if(!isIntakeActive){
    intake_state = 2;
  }
  trapdoor_pos(intake_state);
}

