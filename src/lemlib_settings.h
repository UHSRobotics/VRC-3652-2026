#pragma once 
#include "lemlib/chassis/trackingWheel.hpp" 
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/optical.hpp"


inline pros::Controller master(pros::E_CONTROLLER_MASTER);

inline pros::MotorGroup left_motors({-8,9, -11});      // left motors normal
inline pros::MotorGroup right_motors({15, 18, -17}); // reversed

inline pros::Motor intake(-21);
inline pros::Motor hood(1);

inline pros::IMU imu(4);
inline pros::Optical col_sen(3); //Random Colour sensor, port 3 is temp

inline pros::Rotation horizontal_encoder(5);
inline pros::Rotation vertical_encoder(-6);

inline pros::adi::DigitalOut descore('A', LOW);
inline pros::adi::DigitalOut match_loader('B', LOW);

inline lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              11.5, // 13.5 inch track width (Unsure now, will change later)
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2 
);

inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -0.5);
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -0.4);

inline lemlib::ControllerSettings lateral_controller(
    6,   // kP — proportional gain
    0,    // kI — integral gain
    7,    // kD — derivative gain
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

inline lemlib::ControllerSettings angular_controller(
    4.15,    // kP — proportional gain
    0,    // kI — integral gain
    30,   // kD — derivative gain
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);

inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu); //MIght add horizontal tracking wheel later.

inline lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);  