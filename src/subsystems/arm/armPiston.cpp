// #include "../../../include/robot/armSystem/armPiston.hpp"
// #include "../../../include/globals.hpp"

// ArmPiston::ArmPiston() {}

// void ArmPiston::toggle() {
//   isArmUp = !isArmUp;
//   armPiston.set_value(isArmUp ? 1 : 0);
// }

// void ArmPiston::activate() {
//   isArmUp = true;
//   armPiston.set_value(1);
//   pros::delay(500);
// }

// void ArmPiston::deactivate() {
//   isArmUp = false;
//   armPiston.set_value(0);
//   pros::delay(500);
// }

// bool ArmPiston::getState() const {
//   return isArmUp;
// }

// void ArmPiston::run(pros::controller_digital_e_t button) {
//   if (controller.get_digital_new_press(button)) {
//     toggle();
//   }
// }