#pragma once

#include "lemlib/api.hpp"
#include "lemlib_settings.h"
#include "intake.hpp"
#include "main.h"
#include "lemlib-tarball/api.hpp"
#include "pros/rtos.hpp"

using pros::delay;

inline void shove(int loop){
    //left_motors.move(-1);
	//right_motors.move(-1);
    //delay(500);
    left_motors.move(60);
	right_motors.move(60);
    delay(500);
    left_motors.move(0);
	right_motors.move(0);
    delay(1000);
    for(int i = 0; i < loop; i++){
        left_motors.move(50);
	    right_motors.move(50);
        delay(300);
        left_motors.move(0);
	    right_motors.move(0);
        delay(200);
    }
}


// skills route
ASSET(skills_txt);
inline lemlib_tarball::Decoder decoder_skills(skills_txt);
inline void skills(){
    chassis.setPose(-43.905, 0.196, 0);
    //--Closer side-- 
    chassis.follow(decoder_skills["Path0"], 15, 5000);
    chassis.turnToHeading(270, 5000);
    chassis.waitUntilDone();
    
    forwardIntake();
    match_loader_1.set_value(true); // match loader down
    match_loader_2.set_value(true); // match loader down
    //grab blocks
    chassis.follow(decoder_skills["Path1"], 15, 5000);
    chassis.waitUntilDone();
    shove(10);
    delay(800);
    chassis.follow(decoder_skills["Path2"], 15, 5000, false);
    chassis.waitUntilDone();
    match_loader_1.set_value(false); // match loader up
    match_loader_2.set_value(false); // match loader up
    stopIntake();
    chassis.turnToHeading(0, 5000);
    chassis.follow(decoder_skills["Path3"], 15, 10000);
    chassis.moveToPoint(45.348, 52, 5000);
    chassis.waitUntilDone();
    //--further side--
    chassis.turnToHeading(90, 5000);
    chassis.follow(decoder_skills["Path4"], 15, 5000, false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    delay(4000);
    match_loader_1.set_value(true); // match loader down
    match_loader_2.set_value(true); // match loader down
    chassis.follow(decoder_skills["Path5"], 15, 5000);
    chassis.waitUntilDone();
    forwardIntake();
    shove(10);
    delay(1000);
    chassis.follow(decoder_skills["Path6"], 15, 5000, false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    match_loader_1.set_value(false); // match loader up
    match_loader_2.set_value(false); // match loader up
    delay(3000);
    stopIntake();
    chassis.follow(decoder_skills["Path7"], 15, 5000);
    chassis.turnToHeading(180, 5000);
    chassis.follow(decoder_skills["Path8"], 15, 10000);
    chassis.turnToHeading(90, 5000);
    chassis.waitUntilDone();
    //--still further side but opposite
    match_loader_1.set_value(true); // match loader down
    match_loader_2.set_value(true); // match loader down
    forwardIntakeHoodAuton();
    chassis.follow(decoder_skills["Path9"], 15, 5000);
    chassis.waitUntilDone();
    shove(10);
    delay(1000);
    chassis.follow(decoder_skills["Path10"], 15, 5000,false);
    chassis.waitUntilDone();
    stopIntake();
    match_loader_1.set_value(false); // match loader up
    match_loader_2.set_value(false); // match loader up
    chassis.turnToHeading(180, 5000);
    chassis.follow(decoder_skills["Path11"], 15, 10000);
    //--back to closest side--
    chassis.turnToHeading(270, 5000);
    chassis.follow(decoder_skills["Path12"], 15, 5000,false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    delay(5000);
    match_loader_1.set_value(true); // match loader down
    match_loader_2.set_value(true); // match loader down
    forwardIntake();
    chassis.follow(decoder_skills["Path13"], 15, 5000);
    chassis.waitUntilDone();
    delay(3000);
    chassis.follow(decoder_skills["Path14"], 15, 5000, false);
    chassis.waitUntilDone();
    match_loader_1.set_value(false); // match loader up
    match_loader_2.set_value(false); // match loader up
    forwardIntakeHoodAuton();
    delay(3000);
    stopIntake();
    // --park--
    chassis.follow(decoder_skills["Path15"], 15, 5000);
    chassis.follow(decoder_skills["Path16"], 15, 5000);
    chassis.follow(decoder_skills["Path17"], 15, 5000);
}

/*
ASSET(path_txt)
inline lemlib_tarball::Decoder decoder_path(path_txt);
inline void path(){
    chassis.follow(decoder_path["Path"], 15, 5000, false);
}
*/


