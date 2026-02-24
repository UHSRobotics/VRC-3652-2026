#include "../../include/robot/drivetrain.hpp"
#include "../../include/globals.hpp"

#define DEFAULT_DELAY_LENGTH 15
#define LEFT_ADJUST 1
#define RIGHT_ADJUST 1

// Default drive selection
Drivetrain::DRIVE_MODE Drivetrain::driveMode = CURVATURE_DRIVE;

bool Drivetrain::isReversed = false;

Drivetrain::Drivetrain() { Drivetrain::driveMode = CURVATURE_DRIVE; }

int Drivetrain::thrustHandler(int thrust) {
  if (Drivetrain::isReversed) {
    // Sets each motor to its opposite direction - see globals.cpp for motor ports
    return thrust * -1;
  }
  return thrust;
}

void Drivetrain::curvatureDrive() {
  int left = controller.get_analog(ANALOG_LEFT_Y) * LEFT_ADJUST;
  int right = controller.get_analog(ANALOG_RIGHT_X) * RIGHT_ADJUST;

  chassis.curvature(thrustHandler(left), thrustHandler(right));

  pros::delay(DEFAULT_DELAY_LENGTH);
}

void Drivetrain::arcadeDrive() {
  // Arcade Measurements
  int left = controller.get_analog(ANALOG_LEFT_Y) * LEFT_ADJUST;
  int right = controller.get_analog(ANALOG_RIGHT_X) * RIGHT_ADJUST;

  chassis.arcade(thrustHandler(left), thrustHandler(right), false, 0.6);

  pros::delay(DEFAULT_DELAY_LENGTH);
}

// Run the drivetrain depending on the control mode
void Drivetrain::run(int driveMode) {
  switch (Drivetrain::driveMode) {
  case CURVATURE_DRIVE:
    Drivetrain::curvatureDrive();
    break;
  case ARCADE_DRIVE:
    Drivetrain::arcadeDrive();
    break;
  }
}