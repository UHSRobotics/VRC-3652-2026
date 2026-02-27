#include "main.h"
#include "lemlib/api.hpp"
#include "../include/globals.hpp"
#include "../include/robot/auton.hpp"
#include "../include/screen/autonSelector.hpp"
#include "../include/robot/drivetrain.hpp"
#include "../include/robot/match_load.hpp"
#include "../include/robot/wing.hpp"
#include "../include/robot/intake.hpp"
#include "../include/robot/colorSorter.hpp"

// Robot Instances
AutonSelector autonSelector(5);
Autonomous auton;
Drivetrain drive;
Match_load match_ldr;
Wing wing_descore;
Intake intake;
//ColorSorter colorSorter(intake);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	chassis.calibrate(); // calibrate sensors
	chassis.setPose(0, 0, 0);
	leftMotors.set_brake_modes(BRAKE);
	rightMotors.set_brake_modes(BRAKE);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	controller.print(1, 1, "Starting Selector");
	autonSelector.run();
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	pros::lcd::initialize();
	controller.print(1, 1, "Starting Auton");
  	auton.AutoDrive();
	// print position to brain screen
	pros::Task screen_task([&]() {
		while (true) {
			// print robot location to the brain screen
			pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
			pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
			pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
			// pros::lcd::print(3, "LR: %f", verticalRotation.get_position());
			// pros::lcd::print(4, "RR: %f", horizontalRotation.get_position());
			// delay to save resources
			pros::delay(20);
		}
	});
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
  	chassis.setPose(48, -24, 180);
	pros::lcd::initialize();
	// loop forever
	while (true) {
		// print robot location to the brain screen
		lemlib::Pose p = chassis.getPose();
		controller.print(0, 0, "X:%.2f Y:%.2f Z:%.2f", p.x, p.y, p.theta);
		pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
		pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
		pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
		// pros::lcd::print(3, "LR: %f", verticalRotation.get_position());
		// pros::lcd::print(4, "RR: %f", horizontalRotation.get_position());
		// delay to save resources
		pros::delay(20);

		// Run driver control based on mode selected
		drive.run(drive.CURVATURE_DRIVE);

		match_ldr.run(DIGITAL_A);

		wing_descore.run(DIGITAL_L2);
		
		// armM.controlByAmount(DIGITAL_B, customArmMove, armVelocity);

		intake.holdControl(DIGITAL_R1, DIGITAL_R2, DIGITAL_L1, DIGITAL_X);

		// Run color sorter
		// colorSorter.setTargetColor(DONUT_COLOR::BLUE_RING);
		// colorSorter.sortColor();

		// delay to save resources
		pros::delay(25);
	}
}