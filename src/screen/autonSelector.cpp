#include "pros/adi.hpp"
#include "pros/serial.hpp"
#include "pros/screen.hpp"
#include "pros/rtos.hpp"
#include "../../include/screen/autonSelector.hpp"

#include "../../include/globals.hpp"

AutonSelector::AutonSelector(int maxButtons) : maxButtons(maxButtons)
{
  // Define routes for selection screen (each entry has a name and corresponding route ID)
  routes = {
      {"Left Rush", 1},
      {"Right Rush", 2},
      {"Solo AWP", 3},
      {"forward", -1},
      {"Skills", 0}};
}

void AutonSelector::drawButtons()
{
  int maxCols = 480 / (buttonWidth + spacing);
  int maxRows = 272 / (buttonHeight + spacing);

  for (int i = 0; i < routes.size() && i < maxButtons; i++)
  {
    int col = i % maxCols;
    int row = i / maxCols;
    if (row >= maxRows)
      break;

    int x = col * (buttonWidth + spacing);
    int y = row * (buttonHeight + spacing);

    pros::screen::set_pen(buttonColor);
    pros::screen::fill_rect(x, y, x + buttonWidth, y + buttonHeight);

    pros::screen::set_pen(0xFFFFFF); // White text
    pros::screen::print(textSize, x + 5, y + 5, routes[i].first.c_str());
  }
}

void AutonSelector::display()
{
  pros::screen::set_pen(backgroundColor);
  pros::screen::fill_rect(0, 0, 480, 272);
  drawButtons();
}

bool AutonSelector::handleButtonPress(int16_t x, int16_t y)
{
  if (!firstConfirmation)
  {
    int maxCols = 480 / (buttonWidth + spacing);
    int col = x / (buttonWidth + spacing);
    int row = y / (buttonHeight + spacing);
    int button = row * maxCols + col;

    if (button >= 0 && button < routes.size())
    {
      selectedRoute = button;
      firstConfirmation = true; // Move to confirmation screen
      return true;
    }
  }
  else
  {
    // Check if 'Run' button was pressed
    if (x >= 10 && x <= 230 && y >= 130 && y <= 220)
    {
      finalConfirmation = true;
      active = false; // Exit the loop and move on
    }
    // Check if 'Cancel' button was pressed
    else if (x >= 250 && x <= 470 && y >= 130 && y <= 220)
    {
      firstConfirmation = false; // Reset the process
      selectedRoute = -1;
      return true;
    }
  }
  return false;
}

void AutonSelector::drawConfirmationPrompt()
{
  pros::screen::set_pen(backgroundColor);
  pros::screen::fill_rect(0, 0, 480, 272);
  pros::screen::set_pen(COLOR_WHITE); // White text

  pros::screen::print(textSize, 10, 10, "Selected: %s", routes[selectedRoute].first.c_str());
  pros::screen::print(textSize, 10, 50, "Press to confirm");

  // Draw 'Run' button
  pros::screen::set_pen(COLOR_GREEN); // Green
  pros::screen::fill_rect(10, 130, 230, 220);
  pros::screen::set_pen(COLOR_WHITE); // Black text
  pros::screen::print(pros::E_TEXT_LARGE, 80, 160, "Run");

  // Draw 'Cancel' button
  pros::screen::set_pen(COLOR_RED); // Red
  pros::screen::fill_rect(250, 130, 470, 220);
  pros::screen::set_pen(COLOR_WHITE); // White text
  pros::screen::print(pros::E_TEXT_LARGE, 300, 160, "Cancel");
}

void AutonSelector::finalScreen() {
  pros::screen::set_pen(backgroundColor);
  pros::screen::fill_rect(0, 0, 480, 272);
  pros::screen::set_pen(COLOR_WHITE); // White text
  pros::screen::print(textSize, 10, 10, "Final Selection: %s", routes[selectedRoute].first.c_str());

}
void AutonSelector::executeSelected()
{
  if (selectedRoute >= 0 && selectedRoute < routes.size())
  {
    // Use AutonSwitcher to update the autonomous routine
    Autonomous::AutonSwitcher(routes[selectedRoute].second);
    active = false;
  }
}

// Main method to start the selector process
void AutonSelector::run()
{
  pros::screen::set_pen(backgroundColor);
  pros::screen::fill_rect(0, 0, 480, 272); // Clear the screen initially
  active = true;
  firstConfirmation = false;
  finalConfirmation = false;
  selectedRoute = -1;

  // Display initial route selection buttons
  display();
  controller.print(1, 1, "Showing");

  while (active)
  {
    // Wait for touch input
    pros::screen_touch_status_s_t touch = pros::screen::touch_status();
    if (touch.touch_status == 1) // If screen is being touched
    {
      handleButtonPress(touch.x, touch.y); // Handle touch event

      // If a route was selected or the 'Cancel' button was pressed, redraw the screen
      if (firstConfirmation)
      {
        drawConfirmationPrompt(); // Show confirmation screen
      }
      else
      {
        display(); // Show route selection buttons
      }

      // Wait until touch is released
      while (pros::screen::touch_status().touch_status == 1)
      {
        pros::delay(20); // Small delay to debounce touch
      }

      pros::delay(200); // Small debounce delay after touch
    }

    if (firstConfirmation && finalConfirmation) {
      // Once the route has been confirmed and the "Run" button is pressed, show the final screen
      finalScreen();
      executeSelected();
      pros::delay(2000);
      active = false;
    }

    pros::delay(20); // Small delay to avoid CPU overloading
  }
}
