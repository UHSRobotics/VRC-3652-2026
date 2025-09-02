#pragma once

#include <functional>
#include <vector>
#include <string>
#include "pros/adi.hpp"
#include "pros/serial.hpp"
#include "pros/screen.hpp"
#include "../robot/auton.hpp"

class AutonSelector {
public:
    // Constructor with maximum buttons
    AutonSelector(int maxButtons);

    // Runs the selector UI
    void run();

    // Handles button press on the touchscreen (returns true if screen was redrawn)
    bool handleButtonPress(int16_t x, int16_t y);

    // Draws the autonomous selection buttons
    void display();

    // Draws confirmation prompts (after first selection)
    void drawConfirmationPrompt();

    // Draws Screen with confirmed Route
    void finalScreen();

private:
    // List of routes as (name, autonId) pairs
    std::vector<std::pair<std::string, int>> routes;

    // Maximum number of buttons (routes) that can be displayed
    int maxButtons;

    // UI properties
    int selectedRoute = -1;
    bool firstConfirmation = false;
    bool finalConfirmation = false;

    // Helper methods for drawing buttons
    void drawButtons();

    // Executes the selected route after confirmation
    void executeSelected();

    // State to manage active screen and buttons
    bool active = false;
    int buttonWidth = 140;
    int buttonHeight = 60;
    int spacing = 10;
    uint32_t buttonColor = COLOR_LAVENDER;
    uint32_t backgroundColor = COLOR_DARK_RED;
    pros::text_format_e_t textSize = pros::E_TEXT_MEDIUM;
};