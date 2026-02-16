#include "autons.hpp"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "RobotMechs/PistionIndexerLib.hpp"
#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "pros/motors.h"
#include "subsystems.hpp"
#include "RobotMechs/helpers.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(20.0, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

// . . .
// Make your own autonomous functions here!
// . . .

// -------------------
// Our Push Back Autos
// This section will contain autos for competions and skills
// -------------------
void SevenBlockAutoRedRight() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  chassis.pid_drive_set(10_in, 80);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg,80);
  chassis.pid_wait();
  chassis.pid_drive_set(34.5_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(-8_in, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 80);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  pros::delay(700);
  chassis.pid_drive_set(27_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(-36_in, 55);
  set_match_loader_status(false);
  chassis.pid_wait();
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(2000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // end of auto


}
void SevenBlockWithWingRushRight() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  set_wing_status(true);
  chassis.pid_drive_set(10_in, 80);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(26_in, 80);
  pros::delay(2000);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg,80);
  chassis.pid_wait();
  chassis.pid_drive_set(40_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(82_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(-8_in, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 80);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  chassis.pid_drive_set(7_in, 80);
  chassis.pid_wait();
  // delay before the next action because of matchloader
  pros::delay(950);
  chassis.pid_drive_set(-36_in, 80);
  set_match_loader_status(false);
  chassis.pid_wait();
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(1000);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
  pros::delay(120);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  pros::delay(1000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // going to do wing rush
  chassis.pid_drive_set(10_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(10.5_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-205_deg, 80);
  chassis.pid_wait();
  // going and driving fast
  chassis.pid_drive_set(-19_in, 80);
  chassis.pid_wait();
  set_wing_status(false);
  // end of auto
}

void WinPointOnlyAuto() {
  chassis.pid_drive_set(5_in, 80);
  chassis.pid_wait();
}

void SevenBlockWithWingRushLeft() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  set_wing_status(true);
  chassis.pid_drive_set(10_in, 80);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg,80);
  chassis.pid_wait();
  chassis.pid_drive_set(40_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-82_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(-8_in, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 80);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  chassis.pid_drive_set(7_in, 80);
  chassis.pid_wait();
  // delay before the next action because of matchloader
  pros::delay(950);
  chassis.pid_drive_set(-36_in, 80);
  set_match_loader_status(false);
  chassis.pid_wait();
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(1000);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
  pros::delay(120);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  pros::delay(1000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // going to do wing rush
  chassis.pid_drive_set(-10_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(10.5_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, 80);
  chassis.pid_wait();
  // going and driving fast
  chassis.pid_drive_set(-19_in, 80);
  chassis.pid_wait();
  set_wing_status(false);
  // end of auto
}


void SevenBlockAutoRedLeft() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  chassis.pid_drive_set(7_in, 80);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-45_deg,80);
  chassis.pid_wait();
  chassis.pid_drive_set(34.5_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(-8_in, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 80);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  pros::delay(700);
  chassis.pid_drive_set(27_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(-36_in, 55);
  set_match_loader_status(false);
  chassis.pid_wait();
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(2000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // end of auto
}
void ThreePlusFourBlockAuto() {
  // the three plus four block auto
  chassis.pid_drive_set(32_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-270_deg, 80);
  chassis.pid_wait();
  // going to matchload now
  set_match_loader_status(true);
  pros::delay(1000);
  chassis.pid_drive_set(8.5_in, 80);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // wating for matchloading to finish
  pros::delay(1000);
  // backing up
  IntakeMech.set_intake_status(false);
  chassis.pid_drive_set(-35_in, 80);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // scoring blocks
  pros::delay(2000);
  // lifting up matchloader
  set_match_loader_status(false);
  IntakeMech.set_intake_status(false);
  chassis.pid_drive_set(25_in, 80);
  chassis.pid_wait();
  chassis.pid_turn_set(-135_deg, 80);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  chassis.pid_drive_set(30_in, 80);
  chassis.pid_wait();
  // stopping intake after blocks are in
  IntakeMech.set_intake_status(false);
  chassis.pid_drive_set(15_in, 80);
  chassis.pid_wait();
  // outtaking blocks
  IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
  IntakeMech.set_intake_status(true, 7500);
  pros::delay(1000);
  IntakeMech.set_intake_status(false);

}



void ThreeBlockAutoBottomRed() {
  // the start of our 15 second three block auto for bottom of the middle goal
  // setting bot pos
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  chassis.pid_drive_set(27_in, 55);
  chassis.pid_wait();
  chassis.pid_turn_set(-67_deg, 55);
  IntakeMech.set_intake_status(false);
  chassis.pid_wait();
  chassis.pid_drive_set(16_in, 55);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
  IntakeMech.set_intake_status(true);
  pros::delay(8000);
  IntakeMech.set_intake_status(false);


}

void ThreeBlockAutoTopRed() {
  // the start of our 15 second three block auto for bottom of the middle goal
  chassis.pid_drive_set(28_in, 55);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  chassis.pid_wait();
  IntakeMech.set_intake_status(false);
  chassis.pid_turn_set(67_deg, 55);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, 55);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, 55);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  // mid goal or top goal scoring(IntakeController::Scoring::MID_GOAL);
  pros::delay(8000);
  IntakeMech.set_intake_status(false);
}

void ThreeBlockAutoBottomBlue() {
  // the start of our 15 second three block auto for bottom of the middle goal
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  chassis.pid_drive_set(27_in, 55);
  chassis.pid_wait();
  chassis.pid_turn_set(-68.5_deg, 55);
  IntakeMech.set_intake_status(false);
  chassis.pid_wait();
  chassis.pid_drive_set(16_in, 55);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
  IntakeMech.set_intake_status(true);
  pros::delay(8000);
  IntakeMech.set_intake_status(false);


}

void ThreeBlockAutoTopBlue() {
  // the start of our 15 second three block auto for bottom of the middle goal
  chassis.pid_drive_set(30_in, 55);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  chassis.pid_wait();
  IntakeMech.set_intake_status(false);
  chassis.pid_turn_set(67_deg, 55);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, 55);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, 55);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  pros::delay(8000);
  IntakeMech.set_intake_status(false);
}

// Our skills auto
void SkillsAuto() {
  // our skills auto
  chassis.pid_drive_set(35_in, DRIVE_SPEED);
  chassis.pid_wait();
  // turning to matchloader
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  // deploying matchloader
  set_match_loader_status(true);
  // waitng to make sure it is properly deployed
  pros::delay(700);
  // driving to goal
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status( true, 12000);
  chassis.pid_drive_set(16.7_in, 50);  
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 10);
  chassis.pid_wait();
  // matchloading all blocks
  pros::delay(1);
  IntakeMech.set_intake_status(false);
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  set_match_loader_status(false);
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  // going to other side of the field
  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, 75);
  chassis.pid_wait();
  chassis.pid_drive_set(78_in, DRIVE_SPEED);
  chassis.pid_wait();
  // turning to goal
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-11.5_in, 50);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, 75);
  chassis.pid_wait();
  // truning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  // driving backwards
  chassis.pid_drive_set(-38_in, 50);
  chassis.pid_wait();
  IntakeMech.set_intake_status(true, 12000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  // scoring
  pros::delay(3000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // going to match loader
  chassis.pid_drive_set(15_in, 50);
  chassis.pid_wait();
  // delaying for matchloader
  set_match_loader_status(true);
  pros::delay(700);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 12000);
  chassis.pid_drive_set(20_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 10);
  chassis.pid_wait();
  // going to score
  chassis.pid_drive_set(-38_in, DRIVE_SPEED);
  chassis.pid_wait();
  // scoring
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(3000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  // stoping scoring
  IntakeMech.set_intake_status(false);
  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-180_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(94_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  // delaying for matchloader
  set_match_loader_status(true);
  pros::delay(700);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 12000);
  chassis.pid_drive_set(20_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 10);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  set_match_loader_status(false);
  // going to other side
  chassis.pid_turn_set(190_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(13_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(87_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(12.5_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  // driving backwards
  chassis.pid_drive_set(-38_in, 50);
  chassis.pid_wait();
  IntakeMech.set_intake_status(true, 12000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  // scoring
  pros::delay(3000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // going to match loader
  chassis.pid_drive_set(15_in, 50);
  chassis.pid_wait();
  // delaying for matchloader
  set_match_loader_status(true);
  pros::delay(700);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 12000);
  chassis.pid_drive_set(20_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 10);
  chassis.pid_wait();
  // going to score
  chassis.pid_drive_set(-38_in, DRIVE_SPEED);
  chassis.pid_wait();
  // scoring
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(3000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  // stoping scoring
  IntakeMech.set_intake_status(false);




}