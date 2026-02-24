#pragma once

#include "api.h"
#include "lemlib/api.hpp"

// GEARSET
#define RED pros::E_MOTOR_GEAR_RED
#define GREEN pros::E_MOTOR_GEAR_GREEN
#define BLUE pros::E_MOTOR_GEAR_BLUE

// BREAK MODES
#define COAST pros::E_MOTOR_BRAKE_COAST
#define BRAKE pros::E_MOTOR_BRAKE_BRAKE
#define HOLD pros::E_MOTOR_BRAKE_HOLD

// WHEEL SIZES
#define SIZE_2 2
#define SIZE_275 2.75
#define SIZE_325 3.25
#define SIZE_4 4

// CHASSIS PORTS
#define LEFT_FRONT_MOTOR_PORT 8
#define LEFT_MIDDLE_MOTOR_PORT -9
#define LEFT_BACK_MOTOR_PORT -7
#define RIGHT_FRONT_MOTOR_PORT -1
#define RIGHT_MIDDLE_MOTOR_PORT 2
#define RIGHT_BACK_MOTOR_PORT 3

// CHASSIS VALUES
#define RPM 450
#define TRACK_WIDTH 11.5
// Left to Center
#define VERTICAL_DISPLACEMENT -0.25
// Back to Center
// #define HORIZONTAL_DISPLACEMENT 0.00

// SUBSYSTEMS
#define INTAKE_MOTOR1_PORT 11
#define INTAKE_MOTOR2_PORT -12
extern bool isIntakeActive;

// SENSORS
#define INERTIAL 6
#define VERTICAL_ROTATION 10

// PNEUMATICS
#define TRAPDOOR_B 'H'
#define TRAPDOOR_M 'G'
#define MATCH_LOADER 'B'
#define DESCORE 'A'

// TOGGLE VARIABLES
extern int intake_state;
extern bool trapdoorb_state;
extern bool trapdoorm_state;
extern bool loader_state;
extern bool descore_state;

// CONTROLLER
#define CONTROLLER pros::E_CONTROLLER_MASTER
#define PARTNER pros::E_CONTROLLER_PARTNER

// CONTROLLER BUTTONS
#define DIGITAL_L1 pros::E_CONTROLLER_DIGITAL_L1
#define DIGITAL_L2 pros::E_CONTROLLER_DIGITAL_L2
#define DIGITAL_R1 pros::E_CONTROLLER_DIGITAL_R1
#define DIGITAL_R2 pros::E_CONTROLLER_DIGITAL_R2
#define DIGITAL_A pros::E_CONTROLLER_DIGITAL_A
#define DIGITAL_B pros::E_CONTROLLER_DIGITAL_B
#define DIGITAL_X pros::E_CONTROLLER_DIGITAL_X
#define DIGITAL_Y pros::E_CONTROLLER_DIGITAL_Y
#define DIGITAL_LEFT pros::E_CONTROLLER_DIGITAL_LEFT
#define DIGITAL_RIGHT pros::E_CONTROLLER_DIGITAL_RIGHT
#define DIGITAL_UP pros::E_CONTROLLER_DIGITAL_UP
#define DIGITAL_DOWN pros::E_CONTROLLER_DIGITAL_DOWN
#define ANALOG_LEFT_Y pros::E_CONTROLLER_ANALOG_LEFT_Y
#define ANALOG_RIGHT_X pros::E_CONTROLLER_ANALOG_RIGHT_X


// CHASSIS DEVICES
extern pros::Motor leftFrontMotor;
extern pros::Motor leftMiddleMotor;
extern pros::Motor leftBackMotor;
extern pros::Motor rightFrontMotor;
extern pros::Motor rightMiddleMotor;
extern pros::Motor rightBackMotor;

extern pros::Motor_Group leftMotors;
extern pros::Motor_Group rightMotors;

// SUBSYSTEMS DEVICES
extern pros::Motor leftIntakeMotor;
extern pros::Motor rightIntakeMotor;

extern pros::Motor_Group intakeMotors;

// SENSOR DEVICES
// extern pros::Optical optical;
extern pros::Imu inertial;
extern pros::Rotation verticalRotation;
// extern pros::Rotation horizontalRotation;

// PNEUMATIC DEVICES
extern pros::ADIDigitalOut trapdoor_b;
extern pros::ADIDigitalOut trapdoor_m;
extern pros::ADIDigitalOut match_loader;
extern pros::ADIDigitalOut descore;

// CONTROLLER DEVICES
extern pros::Controller controller;

// LEMLIB SETTINGS
// DRIVE
extern lemlib::Drivetrain drivetrain;
extern lemlib::ExpoDriveCurve steerCurve;
extern lemlib::ExpoDriveCurve throttleCurve;
// ODOM
extern lemlib::TrackingWheel verticalTracking;
// extern lemlib::TrackingWheel horizontalTracking;
extern lemlib::OdomSensors odomSensors;
extern lemlib::ControllerSettings lateralPID;
extern lemlib::ControllerSettings angularPID;
extern lemlib::Chassis chassis;