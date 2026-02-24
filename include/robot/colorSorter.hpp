// #pragma once

// #include "pros/optical.hpp"
// #include "pros/misc.hpp"
// #include "pros/rtos.hpp"
// #include "intake.hpp"
// #include "../globals.hpp"

// class ColorSorter {
//   public:
//     ColorSorter(Intake& intake);

//     void setTargetColor(DONUT_COLOR color);
//     void sortColor();

//   private:
//   Intake& intakeSubsystem;
//   DONUT_COLOR targetColor;
//   // Hue ranges for red and blue colors
//   const double RED_HUE_MIN = 10.0;
//   const double RED_HUE_MAX = 25.0;
//   const double BLUE_HUE_MIN = 200.0;
//   const double BLUE_HUE_MAX = 300.0;
// };