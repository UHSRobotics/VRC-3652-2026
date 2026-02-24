#include "../../include/robot/Match_load.hpp"
#include "../../include/globals.hpp"

Match_load::Match_load() {}

void Match_load::toggle() {
  loader_state = !loader_state;
  match_loader.set_value(loader_state ? 1 : 0);
}

bool Match_load::getState() const {
  return loader_state;
}

void Match_load::run(pros::controller_digital_e_t button) {
  if (controller.get_digital_new_press(button)) {
    toggle();
  }
}

