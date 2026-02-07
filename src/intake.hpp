#pragma once
#include "main.h"
#include "lemlib_settings.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include <atomic>

//MODES:
// 0: DO NOTHING
// 1: MOVE HOOD AND INTAKE FORWARD
// -1: MOVE HOOD AND INTAKE BACKWARD
// 2: MOVE ONLY INTAKE FORWARD
// -2: MOVE ONLY INTAKE BACKWARD
// 3: special auton intake

inline std::atomic<int> intakeState; // holds the current state of the intake

// prevent the intake from fully jamming
inline void preventStuck() {
    // move forward
    intake.move(127);
    pros::delay(100);
    // detect if it isn't moving, if so move back and forth
    if(intake.get_actual_velocity() < 1)
    {
        intake.move(-127);
        pros::delay(70);
        intake.move(127);
        pros::delay(300);
    } 
}

// prevent the intake from fully jamming
inline void preventStuckHood() {
    // move forward
    hood.move(127);
    pros::delay(100);
    // detect if it isn't moving, if so move back and forth
    if(intake.get_actual_velocity() < 1)
    {
        hood.move(-127);
        pros::delay(70);
        hood.move(127);
        pros::delay(300);
    } 
}

inline void intakeTask(void *param) {
    while(true) {
        // read the atomic state and store it in a local variable
        int readState = intakeState.load();
        switch(readState){
            case 0:
                intake.move(0);
                hood.move(0);
                break;
            case 1:
                intake.move(127);
                hood.move(127);
                break;
            case -1:
                intake.move(-127);
                hood.move(-127);
                break;
            case 2:
                intake.move(127);
                hood.move(-5);
                break;
            case -2:
                intake.move(-127);
                hood.move(-5);
                break;
            case 3:
                preventStuck();
                preventStuckHood();
                //hood.move(127);
                break;
            case 4:
                preventStuck();
                hood.move(0);
                break;
        }
        pros::delay(10);
    }
}

// stops all intake moment
inline void stopIntake(){
    intakeState.store(0);
}

// move intake and hood forward
inline void forwardIntakeHood(){
    intakeState.store(1);
}

// reverses intake and hood
inline void reverseIntakeHood(){
    intakeState.store(-1);
}

// move only intake forward
inline void forwardIntake(){
    intakeState.store(2);
}

// move only intake forward
inline void forwardIntakeAuton(){
    intakeState.store(4);
}

// move only intake backward
inline void reverseIntake(){
    intakeState.store(-2);
}

// move intake and hood forward and prevent it from being stuck
inline void forwardIntakeHoodAuton(){
    intakeState.store(3);
}
