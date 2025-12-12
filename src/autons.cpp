#include "autons.hpp"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "RobotMechs/PistionIndexerLib.hpp"
#include "main.h"
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
  chassis.pid_drive_set(10_in, 95);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(-90_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, 95);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  chassis.pid_drive_set(15_in, 95);
  chassis.pid_wait();
  // delay before the next action because of matchloader
  pros::delay(950);
  chassis.pid_drive_set(-35_in, 95);
  set_match_loader_status(false);
  chassis.pid_wait();
  IntakeMech.set_intake_status(IntakeController::Scoring::TOP_GOAL);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(1000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // end of auto


}


void SevenBlockAutoRedLeft() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  chassis.pid_drive_set(10_in, 95);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(90_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(-45_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, 95);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  chassis.pid_drive_set(15_in, 95);
  chassis.pid_wait();
  // delay before the next action because of matchloader
  pros::delay(950);
  chassis.pid_drive_set(-35_in, 95);
  set_match_loader_status(false);
  chassis.pid_wait();
  IntakeMech.set_intake_status(IntakeController::Scoring::TOP_GOAL);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(1000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // end of auto
}

void SevenBlockAutoBlueRight() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  chassis.pid_drive_set(10_in, 95);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(-90_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, 95);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  chassis.pid_drive_set(15_in, 95);
  chassis.pid_wait();
  // delay before the next action because of matchloader
  pros::delay(950);
  chassis.pid_drive_set(-35_in, 95);
  set_match_loader_status(false);
  chassis.pid_wait();
  IntakeMech.set_intake_status(IntakeController::Scoring::TOP_GOAL);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(1000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // end of auto
}

void SevenBlockAutoBlueLeft() {
  // the start of our 15 sec Seven block auto
  // driving the bot the blocks
  chassis.pid_drive_set(10_in, 95);
  chassis.pid_wait();
  // turning on intake
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  // turning the bot to face the three blocks on the corner of mid goal
  chassis.pid_turn_set(90_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(-45_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, 95);
  chassis.pid_wait();
  // activating matchloader
  set_match_loader_status(true);
  chassis.pid_drive_set(15_in, 95);
  chassis.pid_wait();
  // delay before the next action because of matchloader
  pros::delay(950);
  chassis.pid_drive_set(-35_in, 95);
  set_match_loader_status(false);
  chassis.pid_wait();
  IntakeMech.set_intake_status(IntakeController::Scoring::TOP_GOAL);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  pros::delay(1000);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  IntakeMech.set_intake_status(false);
  // end of auto
}



void ThreeBlockAutoBottomRed() {
  // the start of our 15 second three block auto for bottom of the middle goal
  // setting bot pos
  chassis.pid_drive_set(30_in, 55);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  chassis.pid_wait();
  chassis.pid_turn_set(-63_deg, 55);
  IntakeMech.set_intake_status(false);
  chassis.pid_wait();
  chassis.pid_drive_set(18_in, 55);
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
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, 55);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  IntakeMech.set_intake_status(IntakeController::Scoring::TOP_GOAL);
  pros::delay(8000);
  IntakeMech.set_intake_status(false);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
}

void ThreeBlockAutoBottomBlue() {
  // the start of our 15 second three block auto for bottom of the middle goal
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  chassis.pid_drive_set(29_in, 55);
  chassis.pid_wait();
  chassis.pid_turn_set(-71_deg, 55);
  IntakeMech.set_intake_status(false);
  chassis.pid_wait();
  chassis.pid_drive_set(18_in, 55);
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
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, 55);
  chassis.pid_wait();
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true);
  IntakeMech.set_intake_status(IntakeController::Scoring::MID_GOAL);
  pros::delay(8000);
  IntakeMech.set_intake_status(false);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
}

// Our skills auto
void SkillsAuto() {
  // our skills auto
  chassis.pid_drive_set(10_in, 95);
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 10000);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(23_in, 95); 
  chassis.pid_wait();
  // intaking the four balls while turning
  chassis.pid_turn_set(-45_deg, 95);
  chassis.pid_wait();
  // turn off intake
  IntakeMech.set_intake_status(false);
  chassis.pid_drive_set(15_in, 95);
  chassis.pid_wait();
  // outaking 2 of the 4 balls into middle goal
  IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_OPEN);
  IntakeMech.set_intake_status(true, 10000);
  // waiting until all balls are out
  pros::delay(990);
  IntakeMech.set_intake_status(false);
  IndexerMech.set_pistion_status(PistionIndexerLib::INDEXER_CLOSED);
  chassis.pid_drive_set(-10_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, 95);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, 95);
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();
  // setting up for match loding
  set_match_loader_status(true);
  // making sure that match loader is properly deployed
  pros::delay(120);
  chassis.pid_speed_max_set(75);
  chassis.pid_wait();
  chassis.pid_drive_set(15_in, 75);
  chassis.pid_wait();
  // intaking all of the balls
  IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
  IntakeMech.set_intake_status(true, 12000);
  // waiting to finish intake all of the balls
  pros::delay(950);
  IntakeMech.set_intake_status(false, 12000);
   


}