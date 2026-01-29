#include <string>
#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib_settings.h"
#include "lemlib-tarball/api.hpp"
#include "intake.hpp"
#include "routes.hpp"

using namespace std;

string colour_sensor(){
	col_sen.set_led_pwm(100);

	while (true){
		double hue = col_sen.get_hue();

		if (hue < 30 || hue > 330){
			return "RED";
		}
		else if (hue > 200 && hue < 260) {
			return "BLUE";
		}
		else {
			return "I don't know what colour is it";
		}
	}
}

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);

	pros::Task intake_task(intakeTask);

	chassis.calibrate();
	chassis.setPose(0, 0, 0);
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
void competition_initialize() {}

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
    //chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    //chassis.turnToHeading(90, 100000);
    // move 48" forwards
    //chassis.moveToPoint(0, 48, 10000);

    skills();
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

	bool descore_state = false;
	
	bool loader_state = false;

	descore.set_value(descore_state);

	match_loader.set_value(loader_state);

	while (true) {
		
		pros::lcd::set_text(1, "Hello PROS User!");
		master.print(0,0,"%f",chassis.getPose().y);

		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_motors.move(dir + turn);                      // Sets left motor voltage
		right_motors.move(dir - turn);                     // Sets right motor voltage

		//intake control
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
			forwardIntakeHood();
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			reverseIntakeHood();
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			forwardIntake();
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			reverseIntake();
		}
		else{
			stopIntake();
		}

		//match loader control
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
			loader_state = !loader_state;
			match_loader.set_value(loader_state);
		}

		//descore control
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
			descore_state = !descore_state;
			descore.set_value(descore_state);
		}
		pros::delay(20); // Run for 20 ms then update
	}
}