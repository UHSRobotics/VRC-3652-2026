#pragma once 
#include "lemlib/chassis/trackingWheel.hpp" 
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/optical.hpp"


inline pros::Controller master(pros::E_CONTROLLER_MASTER);

inline pros::MotorGroup left_motors({-7, 8, -9});      // left motors normal
inline pros::MotorGroup right_motors({-1, 2, 3}); // reversed

inline pros::Motor intake(-12);
inline pros::Motor hood(11);

inline pros::IMU imu(6);
inline pros::Optical col_sen(3); //Random Colour sensor, port 3 is temp

inline pros::Rotation vertical_encoder(-10);

// trapdoors (3 states)
inline pros::adi::DigitalOut trapdoor_b('H', LOW); // Trapdoor Block
inline pros::adi::DigitalOut trapdoor_m('G', LOW); // Trapdoor Middle
// Match Loader
inline pros::adi::DigitalOut match_loader('B', LOW);
// Descore
inline pros::adi::DigitalOut descore('A', LOW);
// Low Goal Piston
inline pros::adi::DigitalOut low_goal('E', LOW);

inline bool trapdoorb_state = false;
inline bool trapdoorm_state = false;
inline bool loader_state = false;
inline bool descore_state = false;
inline bool lgoal_state = false;

inline lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              11.5, // 13.5 inch track width (Unsure now, will change later)
                              lemlib::Omniwheel::OLD_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2 
);

inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -0.25);

inline lemlib::ControllerSettings lateral_controller(
    10,   // kP — proportional gain
    0,    // kI — integral gain
    1,    // kD — derivative gain
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

inline lemlib::ControllerSettings angular_controller(
    2,    // kP — proportional gain
    0.00,    // kI — integral gain
    1.35,   // kD — derivative gain
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);

inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, nullptr, nullptr, &imu); //MIght add horizontal tracking wheel later.

inline lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);  