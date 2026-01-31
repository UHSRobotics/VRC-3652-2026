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
        left_motors.move(60);
	    right_motors.move(60);
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
    shove(8);
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
    forwardIntake();
    match_loader_1.set_value(true); // match loader down
    match_loader_2.set_value(true); // match loader down
    chassis.follow(decoder_skills["Path5"], 15, 5000);
    chassis.waitUntilDone();
    shove(8);
    delay(800);
    chassis.follow(decoder_skills["Path6"], 15, 5000, false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    match_loader_1.set_value(false); // match loader up
    match_loader_2.set_value(false); // match loader up
    delay(3500);
    stopIntake();
    chassis.follow(decoder_skills["Path7"], 15, 5000);
    chassis.turnToHeading(180, 5000);
    chassis.follow(decoder_skills["Path8"], 15, 10000);
    chassis.turnToHeading(90, 5000);
    chassis.waitUntilDone();
    //--still further side but opposite
    match_loader_1.set_value(true); // match loader down
    match_loader_2.set_value(true); // match loader down
    forwardIntake();
    chassis.follow(decoder_skills["Path9"], 15, 5000);
    chassis.waitUntilDone();
    shove(12);
    delay(1000);
    chassis.follow(decoder_skills["Path10"], 15, 5000,false);
    chassis.waitUntilDone();
    stopIntake();
    match_loader_1.set_value(false); // match loader up
    match_loader_2.set_value(false); // match loader up
    chassis.turnToHeading(180, 5000);
    chassis.follow(decoder_skills["Path11"], 15, 10000);
    chassis.moveToPoint(-35,-48, 5000);
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
    shove(12);
    delay(1000);
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

// auton_r route
ASSET(autonr_txt);
inline lemlib_tarball::Decoder decoder_autonr(autonr_txt);

inline void auton_r(){
    chassis.setPose(-40.429, -3.052, 135); //Set Robot Ini-State;
    chassis.follow(decoder_autonr["Path0"], 15, 5000);
    delay(14); 
    forwardIntake();              
    chassis.waitUntilDone();
    delay(200);
    chassis.turnToHeading(45, 5000);
    chassis.follow(decoder_autonr["Path1"], 15, 5000);
    chassis.waitUntilDone();
    reverseIntake();                        // Outake Middle Low_Goal;
    delay(3000);
    chassis.follow(decoder_autonr["Path2"], 15, 5000, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(225, 5000);
    chassis.follow(decoder_autonr["Path3"], 15, 5000);
    delay(40);
    match_loader_1.set_value(true);         // Match_Loader Down
    match_loader_2.set_value(true);         // Match_Loader Down
    forwardIntake();                        // Start Intake
    chassis.waitUntilDone();
    delay(3000);
    match_loader_1.set_value(false);        // Match_Loader Up
    match_loader_2.set_value(false);        // Match_Loader Up
    chassis.follow(decoder_autonr["Path4"], 15, 5000, false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();                        // Outake R-Long Goal
}

// auton_l route
ASSET(autonl_txt);
inline lemlib_tarball::Decoder decoder_autonl(autonl_txt);

inline void auton_l(){
    chassis.setPose(-45.261, 12.247, 65); //Set Robot Ini-State;
    chassis.follow(decoder_autonl["Path0"], 15, 5000);
    delay(10); 
    forwardIntake();              
    chassis.waitUntilDone();
    delay(800);
    chassis.turnToHeading(315, 5000);
    chassis.follow(decoder_autonl["Path1"], 15, 5000);
    delay(44);
    match_loader_1.set_value(true);        // Match_Loader Down
    match_loader_2.set_value(true);  
    forwardIntake();
    chassis.waitUntilDone();
    chassis.follow(decoder_autonl["Path2"], 15, 5000, false);
    delay(600);
    forwardIntakeHoodAuton();         // Outake L-Long Goal
    delay(5000);
    stopIntake();
    chassis.follow(decoder_autonl["Path3"], 15, 5000);
    shove(4);
    forwardIntakeHoodAuton();         // Outake L-Long Goal
}