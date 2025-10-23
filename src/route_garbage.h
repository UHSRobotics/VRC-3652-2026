#pragma once
#include "main.h"

// Declare all devices (extern = define elsewhere)
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::Optical optical_sensor;

// Function declarations
void movedistance(double distance_mm, int speed);
void detect_color();
void move_forward(int distance_ms);
void move_backward(int distance_ms);
void turn_right();
void route();
