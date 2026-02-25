#include "../include/globals.hpp"

// Global Variables
int intake_state = 0;
bool isIntakeActive = false;
bool trapdoorb_state = false;
bool trapdoorm_state = false;
bool loader_state = false;
bool descore_state = false;

// CHASSIS
pros::Motor leftFrontMotor(LEFT_FRONT_MOTOR_PORT, BLUE);
pros::Motor leftMiddleMotor(LEFT_MIDDLE_MOTOR_PORT, BLUE);
pros::Motor leftBackMotor(LEFT_BACK_MOTOR_PORT, BLUE);
pros::Motor rightFrontMotor(RIGHT_FRONT_MOTOR_PORT, BLUE);
pros::Motor rightMiddleMotor(RIGHT_MIDDLE_MOTOR_PORT, BLUE);
pros::Motor rightBackMotor(RIGHT_BACK_MOTOR_PORT, BLUE);

pros::Motor_Group leftMotors({leftFrontMotor, leftMiddleMotor, leftBackMotor});
pros::Motor_Group rightMotors({rightFrontMotor, rightMiddleMotor, rightBackMotor});

// SUBSYSTEMS
pros::Motor leftIntakeMotor(INTAKE_MOTOR1_PORT, BLUE);
pros::Motor rightIntakeMotor(INTAKE_MOTOR2_PORT, BLUE);

pros::Motor_Group intakeMotors({leftIntakeMotor, rightIntakeMotor});

// SENSORS
//pros::Optical optical(VERTICAL_ROTATION);
pros::Imu inertial(INERTIAL);
pros::Rotation verticalRotation(VERTICAL_ROTATION, true);
// pros::Rotation horizontalRotation(HORIZONTAL_ROTATION);

// PNEUMATICS
pros::ADIDigitalOut trapdoor_b(TRAPDOOR_B);
pros::ADIDigitalOut trapdoor_m(TRAPDOOR_M);
pros::ADIDigitalOut match_loader(MATCH_LOADER);
pros::ADIDigitalOut descore(DESCORE);

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
lemlib::TrackingWheel verticalTracking(&verticalRotation, SIZE_275, VERTICAL_DISPLACEMENT);
// lemlib::TrackingWheel horizontalTracking(&horizontalRotation, SIZE_2, HORIZONTAL_DISPLACEMENT);

lemlib::OdomSensors odomSensors(&verticalTracking,  
                            nullptr,
                            nullptr,
                            nullptr,
                            &inertial);

lemlib::ControllerSettings lateralPID( 7,   // kP — proportional gain
                                        0,    // kI — integral gain
                                        6,    // kD — derivative gain
                                        3, // anti windup
                                        1, // small error range, in inches
                                        100, // small error range timeout, in milliseconds
                                        3, // large error range, in inches
                                        500, // large error range timeout, in milliseconds
                                        20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angularPID(  2,    // kP — proportional gain
                                        0.00,    // kI — integral gain
                                        11,   // kD — derivative gain
                                        3, // anti windup
                                        1, // small error range, in inches
                                        100, // small error range timeout, in milliseconds
                                        3, // large error range, in inches
                                        500, // large error range timeout, in milliseconds
                                        0 // maximum acceleration (slew)
);

lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateralPID, // lateral PID settings
                        angularPID, // angular PID settings
                        odomSensors // odometry
);

