#include "../../include/robot/auton.hpp"
#include "../../include/globals.hpp"
#include "../../include/robot/intake.hpp"

// Default Starting Route
Autonomous::ROUTINE Autonomous::auton = SAWP;
std::string Autonomous::autonName = "Solo - AWP";

Intake intakemotors;

void auton_l(){
    chassis.setPose(-51.22, 11.63, 61);
    descore.set_value(true);
    pros::delay(100);
    descore.set_value(false);
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    // go to blocks in middle
    chassis.moveToPoint(-24, 24, 1050, {.maxSpeed = 80});
    pros::delay(600);
    match_loader.set_value(true);
    // go to in between long goal and loader
    // also note the y value in the below two lines are absurdly large but it works somehow
    //chassis.turnToPoint(-40, -49, 400);
    chassis.moveToPoint(-40, 46.7, 650, {.maxSpeed = 120});
    // face loader and go to it        
    //chassis.turnToHeading(270, 500, {}, false);
    chassis.moveToPoint(-64, 46, 1550,{.minSpeed = 80},false);
    match_loader.set_value(true);
    // score in long goal
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    chassis.moveToPoint(-24, 50, 3000, {.forwards=false, .minSpeed = 80});
    pros::delay(400);
    intakemotors.trapdoor_pos(2);
    match_loader.set_value(false);
    // funny alignment for setting up wing push
    chassis.turnToHeading(330, 1000);
    chassis.moveToPoint(-40, 60, 1000, {.maxSpeed = 120});
    chassis.turnToHeading(270, 1000); 
    // push le blocks in
    while(true){
        chassis.moveToPoint(-14, 60, 1500, {.forwards = false, .maxSpeed = 80});
    }
}

void auton_r(){
    chassis.setPose(-51.22, -11.63, 119);
    descore.set_value(true);
    pros::delay(100);
    descore.set_value(false);
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    // go to blocks in middle
    chassis.moveToPoint(-24, -24, 1050, {.maxSpeed = 80});
    pros::delay(500);
    match_loader.set_value(true);
    // go to in between long goal and loader
    // also note the y value in the below two lines are absurdly large but it works somehow
    //chassis.turnToPoint(-40, -49, 400);
    chassis.moveToPoint(-45, -47, 650, {.maxSpeed = 120});
    // face loader and go to it        
    //chassis.turnToHeading(270, 500, {}, false);
    chassis.moveToPoint(-65, -48, 1450,{.maxSpeed = 80},false);
    match_loader.set_value(true);
    // score in long goal
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    chassis.moveToPoint(-24, -46, 3000, {.forwards=false, .minSpeed = 80});
    pros::delay(400);
    intakemotors.trapdoor_pos(2);
    // funny alignment for setting up wing push
    chassis.turnToHeading(330, 1000);
    chassis.moveToPoint(-33, -35, 1000, {.maxSpeed = 120});
    chassis.turnToHeading(270, 1000); 
    // push le blocks in
    while(true){
        chassis.moveToPoint(-10, -37, 1500, {.forwards = false, .maxSpeed = 70});
    }
}

int squareTimeout = 1250;
void square_auto(){
  chassis.setPose(0, 0, 0);
  chassis.moveToPoint(0,48,squareTimeout, {.maxSpeed=120});
  //chassis.turnToPoint(-48,48,squareTimeout, {.maxSpeed=120});
  chassis.moveToPoint(-48,48,squareTimeout, {.maxSpeed=120});
  //chassis.turnToPoint(-48,0,squareTimeout, {.maxSpeed=120});
  chassis.moveToPoint(-48,0,squareTimeout, {.maxSpeed=120});
  //chassis.turnToPoint(0,0,squareTimeout, {.maxSpeed=120});
  chassis.moveToPoint(0,0,squareTimeout, {.maxSpeed=120});
  chassis.turnToHeading(0,squareTimeout);
}

void sawp(){
    chassis.setPose(-51.22, -11.63, 119);
    descore.set_value(true);
    pros::delay(100);
    descore.set_value(false);
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    // go to blocks in middle
    chassis.moveToPoint(-24, -24, 1050, {.maxSpeed = 80});
    pros::delay(500);
    match_loader.set_value(true);
    // go to in between long goal and loader
    // also note the y value in the below two lines are absurdly large but it works somehow
    //chassis.turnToPoint(-40, -49, 400);
    chassis.moveToPoint(-45, -47, 650, {.maxSpeed = 120});
    // face loader and go to it        
    //chassis.turnToHeading(270, 500, {}, false);
    chassis.moveToPoint(-63, -45, 1450,{.minSpeed = 70}, false);
    match_loader.set_value(true);
    // score in long goal
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    chassis.moveToPoint(-24, -45, 2100, {.forwards=false, .minSpeed = 80});
    pros::delay(400);
    intakemotors.trapdoor_pos(2);
    pros::delay(1700);
    intakemotors.trapdoor_pos(0);
    //Turn to face heading 0;
    chassis.turnToHeading(0, 500, {.minSpeed = 127});
    chassis.setPose(-25.34, -41.42, chassis.getPose().theta);
    pros::delay(10);
    match_loader.set_value(false);
    chassis.moveToPoint(-25, 0, 600, {.maxSpeed = 120, .earlyExitRange = 2.0});
    chassis.moveToPoint(-25, 23, 1500, {.maxSpeed = 80});
    pros::delay(500);
    match_loader.set_value(true);
    //Reach middle goal
    chassis.turnToHeading(-45, 400);
    intakemotors.moveForward(127);
    chassis.moveToPoint(-9, 9, 1600, {.forwards = false, .maxSpeed = 120});
    pros::delay(900);
    intakemotors.trapdoor_pos(1);
    pros::delay(800);
    intakemotors.trapdoor_pos(2);
    pros::delay(100);
    intakemotors.trapdoor_pos(0);
    pros::delay(10);
    //Continue remaining of Left Rush Auton
    // go to in between long goal and loader
    // also note the y value in the below two lines are absurdly large but it works somehow
    chassis.moveToPoint(-40, 46.7, 650, {.maxSpeed = 120});
    match_loader.set_value(true);
    // face loader and go to it        
    //chassis.turnToHeading(270, 500, {}, false);
    chassis.moveToPoint(-67, 45, 1550,{.minSpeed = 80},false);
    // score in long goal
    intakemotors.moveForward(127);
    intakemotors.trapdoor_pos(0);
    chassis.moveToPoint(-24, 50, 3000, {.forwards=false, .maxSpeed = 100});
    pros::delay(500);
    intakemotors.trapdoor_pos(2);
    match_loader.set_value(false);
}

// // Red Left
void Autonomous::Auton1() {
//   chassis.setPose(0, 0, 0);
//   chassis.moveToPoint(0, 24, 5000, {.maxSpeed = 50});
//   chassis.turnToHeading(180, 1000);

}

// // Red Side | Mogo Rush | 5 Rings | AWP
void Autonomous::Auton2() { 

//   chassis.setPose(58.706, -29.938, 90);
//   // chassis.setPose(56.585, -57, 135);

//   //Get First Mogo + Score Preload
//   chassis.moveToPoint(13, -42, 5000, {.forwards = false, .maxSpeed = 127});
//   pros::delay(500);
//   mogoClamp.set_value(true);
//   pros::delay(500);
//   IntakeMotor.move_velocity(600);
//   IndexerMotor.move_velocity(600);
//   pros::delay(1000);
//   IntakeMotor.move_velocity(0);
//   IndexerMotor.move_velocity(0);

//   //Collect Ring Stack
//   chassis.turnToHeading(135, 2000, {.maxSpeed = 127});
//   mogoClamp.set_value(false);
//   chassis.moveToPoint(18, -53, 5000, {.maxSpeed = 127});
//   IntakeMotor.move_velocity(600);
//   IndexerMotor.move_velocity(600);
//   pros::delay(1000);
//   IntakeMotor.move_velocity(0);
//   IndexerMotor.move_velocity(0);
  
//   //Get Second Mogo + Score Collected Ring
//   chassis.moveToPoint(27.914, -23.578, 5000, {.forwards = false, .maxSpeed = 127});
//   pros::delay(500);
//   mogoClamp.set_value(true);
//   pros::delay(500);
//   IntakeMotor.move_velocity(600);
//   IndexerMotor.move_velocity(600);
//   pros::delay(1000);
//   IntakeMotor.move_velocity(0);
//   IndexerMotor.move_velocity(0);

//   //Move To Corner
//   chassis.moveToPoint(55.419, -37, 5000, {.maxSpeed = 127});
//   chassis.moveToPoint(56.585, -57, 2000, {.maxSpeed = 127});
//   chassis.turnToHeading(135, 2000, {.maxSpeed = 127});

//   //Collect Corner Rings
//   IntakeMotor.move_velocity(600);
//   IndexerMotor.move_velocity(600);
//   chassis.moveToPoint(66, -66, 2000, {.maxSpeed = 127});
//   pros::delay(250);
//   chassis.moveToPoint(56.585, -57, 2000, {.forwards = false, .maxSpeed = 127});

//   chassis.moveToPoint(66, -66, 2000, {.maxSpeed = 127});
//   pros::delay(250);
//   chassis.moveToPoint(56.585, -57, 2000, {.forwards = false, .maxSpeed = 127});
//   IntakeMotor.move_velocity(0);
//   IndexerMotor.move_velocity(0);

//   //Collect Second Ring Stack
//       // intakePiston.set_value(true);
//   chassis.moveToPoint(48, 0, 2000, {.maxSpeed = 127});
//       // intakePiston.set_value(false);
//   chassis.moveToPoint(48, -8, 2000, {.forwards = false, .maxSpeed = 127});

//   //Touch Ladder
//   chassis.moveToPoint(11.073, -12.725, 2000, {.forwards = false, .maxSpeed = 127});
}

// // Blue Left
void Autonomous::Auton3() {
}

// // Blue Right Mogo Side(2 Mogos, 1 Rings/Goal, Corner Clear)
void Autonomous::Auton4() {
//   //intake in
//   chassis.setPose(180, -60, 0, false);
//   chassis.turnToHeading(-20, 500);
//   chassis.moveToPose(5, -120, 20, 2000, {.maxSpeed = 80});
//   //clamp clamp
//   chassis.turnToHeading(-70, 1000);
//   chassis.moveToPose(60, -60, -70, 2000, {.maxSpeed = 127});
//   //clamp clamp
//   chassis.turnToHeading(-90, 1000);
//   chassis.moveToPoint(60, -60, 1000, {.maxSpeed = 127});
//   chassis.moveToPose(180, -180, -155, 2000, {.maxSpeed = 127});
//   //doinker is.turnToHeading(-300, 500);
//   chassis.moveToPose(60, 0, -300, 3000, {.maxSpeed = 127});
}

// // Skills
void Autonomous::Auton5() {
//   // intakeMotors.move(127);
}

void Autonomous::AutoDrive() {
  // Compare the current auton value to run the autonomous routine
 switch (Autonomous::auton) {
   case LEFT_RUSH:
      auton_l();
      break;
   case RIGHT_RUSH:
      auton_r();
      break;
   case SAWP:
      sawp();
      break;
   case BLUE_LEFT:
      Auton1();
      break;
   case BLUE_RIGHT:
      square_auto();
      break;
   case SKILLS:
      Auton5();
      break;
   }
}

void Autonomous::AutonSwitcher(int autonNum) {
  switch (autonNum) {
  case 1:
    Autonomous::autonName = "LEFT_RUSH";
    Autonomous::auton = LEFT_RUSH;
    break;
  case 2:
    Autonomous::autonName = "RIGHT_RUSH";
    Autonomous::auton = RIGHT_RUSH;
    break;
  case 3:
    Autonomous::autonName = "Solo - AWP";
    Autonomous::auton = SAWP;
  case -1:
    Autonomous::autonName = "Blue Left";
    Autonomous::auton = BLUE_LEFT;
    break;
  case -2:
    Autonomous::autonName = "Blue Right";
    Autonomous::auton = BLUE_RIGHT;
    break;
  case 0:
    Autonomous::autonName = "Skills";
    Autonomous::auton = SKILLS;
  }
  printf("Current auton: \n", Autonomous::autonName);
}