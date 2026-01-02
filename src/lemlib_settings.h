#pragma once
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/optical.hpp"


inline pros::Controller master(pros::E_CONTROLLER_MASTER);

inline pros::MotorGroup left_motors({-15, 19, -20});      // left motors normal
inline pros::MotorGroup right_motors({16, -11, 14}); // reversed

inline pros::MotorGroup intake({9, 17});

inline pros::IMU imu(10);
inline pros::Optical col_sen(3); //Random Colour sensor, port 10 is temp

inline pros::Rotation horizontal_encoder(2);
inline pros::Rotation vertical_encoder(1);

inline pros::adi::DigitalOut descore('A', LOW);
inline pros::adi::DigitalOut match_loader('B', LOW);

inline lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              11.5, // 13.5 inch track width (Unsure now, will change later)
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2 
);

inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, 5.75);

inline lemlib::ControllerSettings lateral_controller(
    10,   // kP — proportional gain
    0,    // kI — integral gain
    3,    // kD — derivative gain
    3,    // anti-windup
    1,    // small error range (in)
    100,  // small error timeout (ms)
    3,    // large error range (in)
    500,  // large error timeout (ms)
    10    // slew rate limit (in/s)
);

inline lemlib::ControllerSettings angular_controller(
    2,    // kP — proportional gain
    0,    // kI — integral gain
    10,   // kD — derivative gain
    3,    // anti-windup
    1,    // small error range (deg)
    100,  // small error timeout (ms)
    3,    // large error range (deg)
    500,  // large error timeout (ms)
    0     // slew rate limit (deg/s)
);

inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu); //MIght add horizontal tracking wheel later.

inline lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);  