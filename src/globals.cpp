#include "../include/globals.hpp"

// Global Variables
bool isClamped = false;
bool isDoinkerDown = false;
bool isArmUp = false;
bool isTrackDown = false;
bool isIntakeActive = false;
bool isArmActive = false;

// CHASSIS
pros::Motor leftFrontMotor(LEFT_FRONT_MOTOR_PORT, BLUE);
pros::Motor leftMiddleMotor(LEFT_MIDDLE_MOTOR_PORT, BLUE);
pros::Motor leftBackMotor(LEFT_FRONT_MOTOR_PORT, BLUE);
pros::Motor rightFrontMotor(RIGHT_FRONT_MOTOR_PORT, BLUE);
pros::Motor rightMiddleMotor(RIGHT_MIDDLE_MOTOR_PORT, BLUE);
pros::Motor rightBackMotor(RIGHT_BACK_MOTOR_PORT, BLUE);

pros::Motor_Group leftMotors({leftFrontMotor, leftMiddleMotor, leftBackMotor});
pros::Motor_Group rightMotors({rightFrontMotor, rightMiddleMotor, rightMiddleMotor});

// SUBSYSTEMS
pros::Motor armMotorLeft(ARM_MOTOR_LEFT_PORT, GREEN);
pros::Motor armMotorRight(ARM_MOTOR_RIGHT_PORT, GREEN);

pros::Motor leftIntakeMotor(INTAKE_MOTOR_PORT, BLUE);
pros::Motor rightIntakeMotor(INDEXER_MOTOR_PORT, BLUE);

pros::Motor_Group intakeMotors({leftIntakeMotor, rightIntakeMotor});

// SENSORS
//pros::Optical optical(VERTICAL_ROTATION);
pros::Imu inertial(INERTIAL);

// pros::Rotation verticalRotation(VERTICAL_ROTATION);
// pros::Rotation horizontalRotation(HORIZONTAL_ROTATION);

// PNEUMATICS
pros::ADIDigitalOut mogoClamp(MOGO_CLAMP_PORT);
pros::ADIDigitalOut armPiston(INTAKE_PISTON_PORT);
pros::ADIDigitalOut doinkerLeft(DOINKER_LEFT_PORT);
pros::ADIDigitalOut doinkerRight(DOINKER_RIGHT_PORT);

// CONTROLLER
pros::Controller controller(CONTROLLER);

// LEMLIB
lemlib::Drivetrain drivetrain(&leftMotors,
                              &rightMotors,
                              TRACK_WIDTH,
                              SIZE_275,
                              RPM,
                              2);

// Odometry Setup
lemlib::TrackingWheel verticalTracking(&verticalRotation, SIZE_2, VERTICAL_DISPLACEMENT);
// lemlib::TrackingWheel horizontalTracking(&horizontalRotation, SIZE_2, HORIZONTAL_DISPLACEMENT);

lemlib::OdomSensors odom(&verticalTracking,  
                            nullptr,
                            nullptr,
                            nullptr,
                            &inertial);

lemlib::ControllerSettings lateralPID(8, // proportional gain (kP)
                                      0, // integral gain (kI)
                                      3, // derivative gain (kD)
                                      3, // anti windup
                                      1, // small error range, in inches
                                      100, // small error range timeout, in milliseconds
                                      3, // large error range, in inches
                                      500, // large error range timeout, in milliseconds
                                      10 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angularPID(2, // proportional gain (kP)
                                      0, // integral gain (kI)
                                      10, // derivative gain (kD)
                                      3, // anti windup
                                      1, // small error range, in degrees
                                      100, // small error range timeout, in milliseconds
                                      3, // large error range, in degrees
                                      500, // large error range timeout, in milliseconds
                                      0 // maximum acceleration (slew)
);

lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateralPID, // lateral PID settings
                        angularPID, // angular PID settings
                        odomSensors // odometry
);

