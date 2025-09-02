#pragma once

#include <string>
#include "pros/misc.hpp"

class Autonomous {
  public:
    enum ROUTINE { RED_LEFT = 1, RED_RIGHT = 2, BLUE_LEFT = -1, BLUE_RIGHT = -2, SKILLS = 0 };

    /**
     * @brief Sets number of the autonomous program to use
     *
     */
    static ROUTINE auton;

    /**
     * @brief The name of the autonomous program
     *
     */
    static std::string autonName;

    /**
     * @brief robot autonomously based on selected autonomous program
     */
    void AutoDrive();

    /**
     * @brief This function switches the autonomous program to the next available program.
     * It allows the user to cycle through different autonomous programs during runtime.
     *
     */
    static void AutonSwitcher(int autonNum);

    private:

    /**
     * @brief Runs autonomous for red far side defensive game strategy.
     *
     */
    void Auton1();

    /**
     * @brief Runs autonomous for red near side offensive game strategy.
     *
     */
    void Auton2();
    /**
     * @brief Runs autonomous for blue far side defensive game strategy.
     *
     */
    void Auton3();
    /**
     * @brief Runs autonomous for blue far side defensive game strategy.
     *
     */
    void Auton4();
    /**
     * @brief Runs autonomous for skills challenge
     *
     */
    void Auton5();

};