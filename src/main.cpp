#include <string>
#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib_settings.h"
#include "lemlib-tarball/api.hpp"
#include "intake.hpp"
#include "pros/colors.hpp"
#include "pros/screen.hpp"
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

int auton_select = 0;

void drawButtons(){
	pros::screen::erase();
	//Skills
	pros::screen::set_pen(pros::c::COLOR_RED);
	pros::screen::fill_rect(10, 50, 110, 100);
	pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(TEXT_MEDIUM, 50, 75, "Skills");
	//button 2
	pros::screen::set_pen(pros::c::COLOR_BLUE);
	pros::screen::fill_rect(140, 50, 240, 100);
	pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(TEXT_MEDIUM, 190, 75, "Autonl");
	//button 3
	pros::screen::set_pen(pros::c::COLOR_RED);
	pros::screen::fill_rect(260, 50, 360, 100);
	pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(TEXT_MEDIUM, 300, 75, "Autonr");
	//button 4
	pros::screen::set_pen(pros::c::COLOR_BLUE);
	pros::screen::fill_rect(10, 110, 110, 210);
	pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(TEXT_MEDIUM, 50, 160, "Auton4");
	//button5
	pros::screen::set_pen(pros::c::COLOR_RED);
	pros::screen::fill_rect(140, 110, 240, 210);
	pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(TEXT_MEDIUM, 190, 160, "Auton5");
	//button 6
	pros::screen::set_pen(pros::c::COLOR_BLUE);
	pros::screen::fill_rect(260, 110, 360, 210);
	pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(TEXT_MEDIUM, 300, 160, "Auton6");
}

void execAuto(){
	pros::screen_touch_status_s_t status = pros::screen::touch_status();
	//Skills button
	if (status.x > 10 && status.x < 110 && status.y > 50 && status.y < 100) {
		auton_select = 1;
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(TEXT_MEDIUM, 10, 200, "READY: Skills ");
		
    } 
	//button 2
    else if (status.x > 140 && status.x < 240 && status.y > 50 && status.y < 100) {
		auton_select = 2;
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(TEXT_MEDIUM, 10, 200, "READY: Autonl ");
    }
	//button 3
	else if (status.x > 260 && status.x < 360 && status.y > 50 && status.y < 100) {
		auton_select = 3;
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(TEXT_MEDIUM, 10, 200, "READY: Autonr ");
    }
	//button 4
	else if (status.x > 10 && status.x < 110 && status.y > 110 && status.y < 210) {
		auton_select = 4;
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(TEXT_MEDIUM, 10, 200, "READY: Auton4 ");
		
    } 
	//button 5
    else if (status.x > 140 && status.x < 240 && status.y > 110 && status.y < 210) {
		auton_select = 5;
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(TEXT_MEDIUM, 10, 200, "READY: Auton5 ");
    }
	//button 6
	else if (status.x > 260 && status.x < 360 && status.y > 110 && status.y < 210) {
		auton_select = 6;
        pros::screen::set_pen(pros::c::COLOR_WHITE);
        pros::screen::print(TEXT_MEDIUM, 10, 200, "READY: Auton6 ");
    }
}

void autonSelect(){
    drawButtons();
    pros::screen::touch_callback(execAuto, TOUCH_PRESSED);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//pros::lcd::initialize();
	//pros::lcd::set_text(1, "Hello PROS User!");

	pros::Task intake_task(intakeTask);

	chassis.calibrate();
	//chassis.setPose(0, 0, 0);

	autonSelect();
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
	descore.set_value(true);
    //chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    //chassis.turnToHeading(90, 100000);
    // move 48" forwards
    //chassis.moveToPoint(0, 48, 10000);
    // if(auton_select == 1){
	// 	skills();
	// }
	// else if (auton_select == 2){
	// 	auton_l();
	// }
	// else if (auton_select == 3){
	// 	auton_r();
	// }
	//auton_l();
	// skills();
	//auton_l();
	auton_r2();
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

	match_loader_1.set_value(loader_state);
	match_loader_2.set_value(loader_state);

	//left_motors.set_brake_mode_all(MOTOR_BRAKE_COAST);
	//right_motors.set_brake_mode_all(MOTOR_BRAKE_COAST);

	left_motors.set_brake_mode_all(MOTOR_BRAKE_HOLD);
	right_motors.set_brake_mode_all(MOTOR_BRAKE_HOLD);

	while (true) {
		
		pros::lcd::set_text(1, "Hello PROS User!");
		master.print(0,0,"%f",chassis.getPose().x);

		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_motors.move(dir + turn);                      // Sets left motor voltage
		right_motors.move(dir - turn);                     // Sets right motor voltage

		//intake control
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
			forwardIntake();
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			reverseIntakeHood();
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			forwardIntakeHood();
		} 
		else{
			stopIntake();
		}

		//match loader control
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
			loader_state = !loader_state;
			match_loader_1.set_value(loader_state);
			match_loader_2.set_value(loader_state);
		}

		//descore control
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
			descore_state = !descore_state;
			descore.set_value(descore_state);
		}
		pros::delay(20); // Run for 20 ms then update
	}
}