#pragma once

#include <string>

class Drivetrain {
  public:

  /**
   * @brief Drivetrain constructor
   *
   */
  Drivetrain();

  /**
   * @brief Drive control schemes
   *
   */
  enum DRIVE_MODE { CURVATURE_DRIVE = 0, ARCADE_DRIVE = 1, TANK_DRIVE = 2 };

  /**
   * @brief Active drive control scheme
   *
   */
  static DRIVE_MODE driveMode;

  /**
   * @brief Run drivetrain based on mode selected
   *
   */
  void run(int driveMode);

  /**
   * @brief Toggle through each drivetrain control mode
   *
   */
  static std::string toggleDrive();

  /**
   * @brief Toggles the orientation of the drivetrain
   *
   */
  static int thrustHandler(int thrust);

  static bool isReversed;

  private:

  /**
   * @brief Drives robot using arcade drive
   * Arcade drive uses the left joystick for forward and backward movement, and
   * the right joystick for left and right movement.
   */
  void arcadeDrive();

  /**
   * @brief Drives using curvature drive
   * Curvature drive applies curvature to turns and a negative inertia
   * accumulator.
   *
   */
  void curvatureDrive();
};