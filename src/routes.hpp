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
    
    forwardIntakeHood(0);
    match_loader.set_value(true); // match loader down
    //grab blocks
    chassis.follow(decoder_skills["Path1"], 15, 1000);
    chassis.waitUntilDone();
    shove(3);
    //delay(2000);
    chassis.follow(decoder_skills["Path2"], 15, 5000, false);
    chassis.waitUntilDone();
    match_loader.set_value(false); // match loader up
    stopIntake(0);
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
    forwardIntakeHood(0);
    delay(4000);
    forwardIntakeHood(0);
    match_loader.set_value(true); // match loader down
    //chassis.follow(decoder_skills["Path5"], 15, 5000);
    chassis.moveToPoint(58.4,39,2000);
    chassis.waitUntilDone();
    shove(3);
    //delay(500);
    //chassis.follow(decoder_skills["Path6"], 15, 5000, false);
    chassis.moveToPoint(31,40,2000,{.forwards=false});
    chassis.waitUntilDone();
    forwardIntakeHood(0);
    match_loader.set_value(false); // match loader up
    delay(3500);
    stopIntake(0);
    //chassis.follow(decoder_skills["Path7"], 15, 5000);
    chassis.moveToPoint(39, 41, 5000);
    chassis.turnToHeading(180, 5000);
    //chassis.follow(decoder_skills["Path8"], 15, 10000);
    chassis.moveToPoint(39, -54, 5000);
    chassis.turnToHeading(90, 5000);
    chassis.waitUntilDone();
    //--still further side but opposite
    match_loader.set_value(true); // match loader down
    forwardIntakeHood(0);
    //chassis.follow(decoder_skills["Path9"], 15, 5000);
    chassis.moveToPoint(54.6, -54, 5000);
    chassis.waitUntilDone();
    shove(3);
    //delay(500);
    //chassis.follow(decoder_skills["Path10"], 15, 5000,false);
    chassis.moveToPoint(39, -54, 5000, {.forwards=false});
    chassis.waitUntilDone();
    stopIntake(0);
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
    forwardIntakeHood(0);
    delay(5000);
    match_loader.set_value(true); // match loader down
    forwardIntakeHood(0);
    chassis.follow(decoder_skills["Path13"], 15, 5000);
    chassis.waitUntilDone();
    shove(10);
    //delay(2000);
    chassis.follow(decoder_skills["Path14"], 15, 5000, false);
    chassis.waitUntilDone();
    match_loader.set_value(false); // match loader up
    forwardIntakeHood(0);
    delay(3000);
    stopIntake(0);
    // --park--
    //chassis.follow(decoder_skills["Path15"], 15, 5000);
    //chassis.follow(decoder_skills["Path16"], 15, 5000);
    //chassis.follow(decoder_skills["Path17"], 15, 5000);
}

// auton_l route
ASSET(autonl_txt);
inline lemlib_tarball::Decoder decoder_autonl(autonl_txt);

inline void auton_l(){
    chassis.setPose(-50.03, 9.90, 64); //Set Robot Ini-State;
    delay(10);
    forwardIntakeHood(0);
    chassis.moveToPoint(-22.027, 22.29, 1500, {.maxSpeed = 120, .earlyExitRange = 2.0});
    delay(500);
    match_loader.set_value(true);
    chassis.turnToHeading(315, 3000);
    chassis.moveToPoint(-48, 48, 1500, {.maxSpeed = 120, .earlyExitRange = 2.0});              
    chassis.turnToHeading(265, 500);
    chassis.moveToPoint(-53, 48, 500);
    delay(2000);
    chassis.moveToPoint(-24, 48, 1500, {.forwards=false, .maxSpeed = 120, .earlyExitRange = 2.0});
    chassis.waitUntilDone();
    trapdoor_pos(2);
    delay(3000);

    chassis.turnToHeading(330, 1000);
    chassis.moveToPoint(-36, 59, 500, {.maxSpeed = 120, .earlyExitRange = 2.0});
    chassis.turnToHeading(265, 500);
    while(true){    
        chassis.moveToPoint(-7, 59, 1500, {.forwards = false, .maxSpeed = 120});
    }
}

// auton r route
ASSET(autonr2_txt);
inline lemlib_tarball::Decoder decoder_autonr2(autonr2_txt);

inline void auton_r(){
    chassis.setPose(-51.22, -11.63, 119);
    delay(10);
    forwardIntakeHood(0);
    chassis.moveToPoint(-24, -24, 1500, {.maxSpeed = 80, .earlyExitRange = 2.0});
    delay(500);
    match_loader.set_value(true);
    chassis.turnToPoint(-35, -51, 500);
    chassis.moveToPoint(-35, -51, 1500, {.maxSpeed = 120});              
    chassis.turnToHeading(270, 500);
    delay(10);
    chassis.moveToPoint(-60, -51, 1000, {.maxSpeed = 50}, false);
    forwardIntakeHood(0);
    delay(3000);
    chassis.moveToPoint(-24, -51, 1500, {.forwards=false, .maxSpeed = 120});
    chassis.waitUntilDone();
    trapdoor_pos(2);
    delay(1500);
    chassis.turnToHeading(330, 1000);
    chassis.moveToPoint(-35, -39, 1000, {.maxSpeed = 120});
    chassis.turnToHeading(258, 1000); 
    while(true){
        chassis.moveToPoint(-7, -39, 1500, {.forwards = false, .maxSpeed = 50});
    }
}

inline void auton_sawp(){
    chassis.setPose(-51.22, -11.63, 119);
    delay(10);
    forwardIntakeHood(0);
    chassis.moveToPoint(-24, -24, 1500, {.maxSpeed = 60});
    delay(500);
    match_loader.set_value(true);
    chassis.turnToHeading(225, 3000);
    chassis.moveToPoint(-49, -49, 1500, {.maxSpeed = 120});              
    chassis.turnToHeading(275, 500);
    delay(10);
    forwardIntakeHood(0);
    chassis.moveToPoint(-53, -49, 500);
    delay(2000);
    chassis.moveToPoint(-24, -48, 1500, {.forwards=false, .maxSpeed = 120});
    chassis.waitUntilDone();
    trapdoor_pos(2);
    delay(2000);
    trapdoor_pos(0);
    match_loader.set_value(false);
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(-22.027, 22.29, 1500, {.maxSpeed = 120, .earlyExitRange = 2.0});
    delay(700);
    match_loader.set_value(true);
    chassis.turnToHeading(315, 3000);
    chassis.moveToPoint(-15, 15, 1500, {.forwards = false, .maxSpeed = 120, .earlyExitRange = 2.0});
    trapdoor_pos(1);
    delay(1000);
    trapdoor_pos(0);
    chassis.moveToPoint(-48, 48, 1500, {.maxSpeed = 120, .earlyExitRange = 2.0});              
    chassis.turnToHeading(265, 500);
    chassis.moveToPoint(-53, 48, 500);
    delay(2000);
    chassis.moveToPoint(-24, 48, 1500, {.forwards=false, .maxSpeed = 120, .earlyExitRange = 2.0});
    chassis.waitUntilDone();
    trapdoor_pos(2);
    delay(3000);
}