// #include "../../include/robot/colorSorter.hpp"
// #include "../../include/globals.hpp"
// #include "../../include/robot/intake.hpp"

// ColorSorter::ColorSorter(Intake& intake) : intakeSubsystem(intake) {}

// void ColorSorter::setTargetColor(DONUT_COLOR color) {
//   targetColor = color;
// }

// void ColorSorter::sortColor() {
//   // Get the hue value from the optical sensor
//   double hue = optical.get_hue();

//   // Check if the hue value is within the red range
//   if (hue >= RED_HUE_MIN && hue <= RED_HUE_MAX && targetColor == DONUT_COLOR::RED_RING)
//   {
//     pros::lcd::print(6, "RED");
//     intakeSubsystem.stop();
//     pros::delay(200);
//     intakeSubsystem.moveBackward(64); // Move the motor forward (e.g., intake forward)
//     pros::delay(2000);
//     intakeSubsystem.moveForward(127);
//   }
//   // Check if the hue value is within the blue range
//   else if (hue >= BLUE_HUE_MIN && hue <= BLUE_HUE_MAX && targetColor == DONUT_COLOR::BLUE_RING)
//   {
//     pros::lcd::print(6, "BLUE");
//     intakeSubsystem.stop();
//     pros::delay(200);
//     intakeSubsystem.moveBackward(64); // Move the motor backward (e.g., intake backward)
//     pros::delay(2000);
//     intakeSubsystem.moveForward(127);
//   }
//   else
//   {
//     pros::lcd::print(6, "NONE");
//   }
// }