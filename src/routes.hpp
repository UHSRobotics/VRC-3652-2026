#pragma once

#include "lemlib/api.hpp"
#include "lemlib_settings.h"
#include "intake.hpp"
#include "main.h"
#include "lemlib-tarball/api.hpp"
#include "pros/rtos.hpp"

using pros::delay;

inline void shove(int loop){
    /*left_motors.move_velocity(45);
	right_motors.move_velocity(45);
    delay(loop);
    left_motors.move_velocity(0);
	right_motors.move_velocity(0);
    delay(500);*/
    
    left_motors.move(45);
	right_motors.move(45);
    delay(500);
    left_motors.move(0);
	right_motors.move(0);
    delay(1000);
    for(int i = 0; i < loop; i++){
        left_motors.move(45);
	    right_motors.move(45);
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

    descore.set_value(true);
    //--Closer side-- 
    chassis.moveToPoint(-43.6, 45.128, 5000);
    //chassis.follow(decoder_skills["Path0"], 15, 5000);
    chassis.turnToHeading(270, 5000);
    chassis.waitUntilDone();
    
    forwardIntakeAuton();
    match_loader.set_value(true); // match loader down
    //grab blocks
    chassis.follow(decoder_skills["Path1"], 15, 1000);
    chassis.waitUntilDone();
    shove(3);
    //delay(2000);
    chassis.follow(decoder_skills["Path2"], 15, 5000, false);
    chassis.waitUntilDone();
    match_loader.set_value(false); // match loader up
    stopIntake();
    chassis.turnToHeading(180, 5000);
    // NOTE TO SELF REPLACE THESE WITH MOVE TO POINTS AND TURN TO HEADINGS
    //chassis.follow(decoder_skills["Path3"], 15, 10000);
    chassis.moveToPoint(-38.8, 31, 5000);
    chassis.turnToPoint(39.846, 30, 5000);
    chassis.moveToPoint(39.846, 30, 5000);
    chassis.moveToPoint(45.348, 40, 5000);
    chassis.waitUntilDone();
    //--further side--
    chassis.turnToHeading(90, 5000);
    //chassis.follow(decoder_skills["Path4"], 15, 5000, false);
    chassis.moveToPoint(31,40,2000,{.forwards=false});
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    delay(4000);
    forwardIntakeAuton();
    match_loader.set_value(true); // match loader down
    //chassis.follow(decoder_skills["Path5"], 15, 5000);
    chassis.moveToPoint(58.4,39,2000);
    chassis.waitUntilDone();
    shove(3);
    //delay(500);
    //chassis.follow(decoder_skills["Path6"], 15, 5000, false);
    chassis.moveToPoint(31,40,2000,{.forwards=false});
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    match_loader.set_value(false); // match loader up
    delay(3500);
    stopIntake();
    //chassis.follow(decoder_skills["Path7"], 15, 5000);
    chassis.moveToPoint(39, 41, 5000);
    chassis.turnToHeading(180, 5000);
    //chassis.follow(decoder_skills["Path8"], 15, 10000);
    chassis.moveToPoint(39, -54, 5000);
    chassis.turnToHeading(90, 5000);
    chassis.waitUntilDone();
    //--still further side but opposite
    match_loader.set_value(true); // match loader down
    forwardIntakeAuton();
    //chassis.follow(decoder_skills["Path9"], 15, 5000);
    chassis.moveToPoint(54.6, -54, 5000);
    chassis.waitUntilDone();
    shove(3);
    //delay(500);
    //chassis.follow(decoder_skills["Path10"], 15, 5000,false);
    chassis.moveToPoint(39, -54, 5000, {.forwards=false});
    chassis.waitUntilDone();
    stopIntake();
    match_loader.set_value(false); // match loader up
    chassis.turnToHeading(0, 5000);
    //chassis.follow(decoder_skills["Path11"], 15, 10000);
    chassis.moveToPoint(38.8, -31, 5000);
    chassis.turnToPoint(39.846, -30, 5000);
    chassis.moveToPoint(39.846, -30, 5000);
    chassis.moveToPoint(-35,-48, 5000);
    //--back to closest side--
    chassis.turnToHeading(270, 5000);
    chassis.follow(decoder_skills["Path12"], 15, 5000,false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();
    delay(5000);
    match_loader.set_value(true); // match loader down
    forwardIntakeAuton();
    chassis.follow(decoder_skills["Path13"], 15, 5000);
    chassis.waitUntilDone();
    shove(10);
    //delay(2000);
    chassis.follow(decoder_skills["Path14"], 15, 5000, false);
    chassis.waitUntilDone();
    match_loader.set_value(false); // match loader up
    forwardIntakeHoodAuton();
    delay(3000);
    stopIntake();
    // --park--
    //chassis.follow(decoder_skills["Path15"], 15, 5000);
    //chassis.follow(decoder_skills["Path16"], 15, 5000);
    //chassis.follow(decoder_skills["Path17"], 15, 5000);
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
    /*chassis.turnToHeading(45, 5000);
    chassis.follow(decoder_autonr["Path1"], 15, 5000);
    chassis.waitUntilDone();
    reverseIntake();                        // Outake Middle Low_Goal;
    delay(3000);
    chassis.follow(decoder_autonr["Path2"], 15, 5000, false);
    chassis.waitUntilDone();*/
    chassis.turnToHeading(225, 5000);
    chassis.follow(decoder_autonr["Path3"], 15, 5000);
    chassis.waitUntilDone();
    delay(40); 
    match_loader.set_value(true);         // Match_Loader Down
    forwardIntake();                        // Start Intake
    chassis.waitUntilDone();
    delay(3000);
    match_loader.set_value(false);        // Match_Loader Up
    chassis.follow(decoder_autonr["Path4"], 15, 5000, false);
    chassis.waitUntilDone();
    forwardIntakeHoodAuton();                        // Outake R-Long Goal
}


// auton_l route
ASSET(autonl_txt);
inline lemlib_tarball::Decoder decoder_autonl(autonl_txt);

inline void auton_l(){
    chassis.setPose(-49.22, 10.99, 63); //Set Robot Ini-State;
    delay(10);
    forwardIntakeHood();
    chassis.moveToPoint(-22.027, 22.29, 1500, {.maxSpeed = 50});
    chassis.turnToHeading(315, 3000);
    delay(10);
    stopIntake();
    // match_loader.set_value(true);
    chassis.moveToPoint(-49, 49, 1500, {.maxSpeed = 50});              
    chassis.turnToHeading(260, 3000);
    delay(10);
    forwardIntakeHood();
    chassis.moveToPoint(-53, 49, 500);
    chassis.moveToPoint(-24, 49, 1500, {.forwards=false, .maxSpeed = 50});
    chassis.waitUntilDone();
    chassis.turnToHeading(330, 1500);
    chassis.moveToPoint(-35, 59, 1500, {.maxSpeed = 50});
    chassis.turnToHeading(265, 1500);
    chassis.moveToPoint(-10, 60, 1500, {.forwards = false, .maxSpeed = 50});
    
}

// auton_l route
ASSET(autonr2_txt);
inline lemlib_tarball::Decoder decoder_autonr2(autonr2_txt);

inline void auton_r2(){
    chassis.setPose(-45.261, -12.247, 115); //Set Robot Ini-State;
    //chassis.follow(decoder_autonr2["Path0"], 15, 5000);
    chassis.moveToPoint(-24.325, -21.406, 2000);
    delay(10); 
    forwardIntake();
    chassis.waitUntilDone();
    delay(800);
    chassis.turnToHeading(225, 5000);
    //chassis.follow(decoder_autonr2["Path1"], 15, 5000);
    chassis.moveToPoint(-38,-52,2000);
    chassis.waitUntilDone();
    chassis.turnToPoint(-59.352, -52,2000);
    chassis.waitUntilDone();
    delay(44);
    match_loader.set_value(true);        // Match_Loader Down
    forwardIntake();
    delay(500);
    chassis.moveToPoint(-59.352, -52,2000);
    chassis.waitUntilDone();
    //chassis.follow(decoder_autonr2["Path2"], 15, 5000, false);
    delay(2000);
    chassis.moveToPoint(-25.332, -52,2000,{.forwards=false});
    chassis.waitUntilDone();
    delay(100);
    forwardIntakeHoodAuton();         // Outake L-Long Goal
    delay(5000);
    stopIntake();
    chassis.follow(decoder_autonr2["Path3"], 15, 5000);
    shove(4);
    forwardIntakeHoodAuton();         // Outake L-Long Goal
}