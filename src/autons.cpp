#include "autons.hpp"
#include "main.h"
#include "subsystems.hpp"

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

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .

// -------------------
// Our Push Back Autos
// This section will contain autos for competions and skills
// -------------------
void FiveBlockAutoRedRight() {
  // the start of our 15 sec five block auto
  // setting bot starting pos
  chassis.odom_xyt_set(-47.363_in, 12.803_in, 0_deg);
  chassis.pid_odom_set({{-47.586_in, 46.195_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-62.896_in, 46.195_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // goes to loader to intake 3 blocks
  // intaking blocks
  // reverse to go to 2 blocks by mid goal
  chassis.pid_odom_set({{-23.927_in, 15.02_in, 0_deg}, rev, DRIVE_SPEED});
  chassis.pid_wait();
  // goes foward and intakes the 2 blocks by mid
  // intaking while driving
  chassis.pid_odom_set({{-23.893_in, 35.241_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // stoping intake and moving to next cord
  chassis.pid_odom_set({{-39.354_in, 35.74_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // going to long goal
  chassis.pid_odom_set({{-39.109_in, 47.621_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-25.956_in, 47.105_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // running intake to deposit all blocks into goal
  // stopping intake
  // end of code

}

void FiveBlockAutoRedLeft() {
  // the start of our 15 sec five block auto
  // setting bot starting pos
  chassis.odom_xyt_set(-47.621_in, -16.599_in, 180_deg);
  chassis.pid_odom_set({{-47.586_in, -46.195_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-62.896_in, -46.195_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // goes to loader to intake 3 blocks
  // intaking blocks
  // reverse to go to 2 blocks by mid goal
  chassis.pid_odom_set({{-23.927_in, -15.02_in, 180_deg}, rev, DRIVE_SPEED});
  chassis.pid_wait();
  // goes foward and intakes the 2 blocks by mid
  // intaking while driving
  chassis.pid_odom_set({{-23.893_in, -35.241_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // stoping intake and moving to next cord
  chassis.pid_odom_set({{-39.354_in, -35.74_in, 180_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // going to long goal
  chassis.pid_odom_set({{-39.109_in, -47.621_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-25.956_in, -47.105_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // running intake to deposit all blocks into goal
  // stopping intake
  // end of code
}

void FiveBlockAutoBlueRight() {
  // the start of our 15 sec five block auto
  // setting bot starting pos
  chassis.odom_xyt_set(47.621_in, 16.599_in, 0_deg);
  chassis.pid_odom_set({{47.586_in, 46.195_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{62.896_in, 46.195_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // goes to loader to intake 3 blocks
  // intaking blocks
  // reverse to go to 2 blocks by mid goal
  chassis.pid_odom_set({{23.927_in, 15.02_in, 0_deg}, rev, DRIVE_SPEED});
  chassis.pid_wait();
  // goes foward and intakes the 2 blocks by mid
  // intaking while driving
  chassis.pid_odom_set({{23.893_in, 35.241_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // stoping intake and moving to next cord
  chassis.pid_odom_set({{-39.354_in, -35.74_in, 180_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // going to long goal
  chassis.pid_odom_set({{39.354_in, 35.74_in, 0_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{39.109_in, 47.621_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // running intake to deposit all blocks into goal
  // stopping intake
  // end of code
}

void FiveBlockAutoBlueLeft() {
  // the start of our 15 sec five block auto
  // setting bot starting pos
  chassis.odom_xyt_set(47.621_in, -16.599_in, 180_deg);
  chassis.pid_odom_set({{47.586_in, -46.195_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{62.896_in, -46.195_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // goes to loader to intake 3 blocks
  // intaking blocks
  // reverse to go to 2 blocks by mid goal
  chassis.pid_odom_set({{23.927_in, -15.02_in, 180_deg}, rev, DRIVE_SPEED});
  chassis.pid_wait();
  // goes foward and intakes the 2 blocks by mid
  // intaking while driving
  chassis.pid_odom_set({{23.893_in, -35.241_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // stoping intake and moving to next cord
  chassis.pid_odom_set({{39.354_in, -35.74_in, 180_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // going to long goal
  chassis.pid_odom_set({{39.109_in, -47.621_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{25.956_in, -47.105_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // running intake to deposit all blocks into goal
  // stopping intake
  // end of code
}

void ThreeBlockAutoBottomRed() {
  // the start of our 15 second three block auto for bottom of the middle goal
  // setting bot pos
  chassis.odom_xyt_set(-51.747_in, -12.545_in, 130_deg);
  chassis.pid_odom_set({{-38.594_in, -23.119_in, 90_deg}, fwd, DRIVE_SPEED});
  // turning on intake
  chassis.pid_wait();
  chassis.pid_odom_set({{-21.056_in, -23.893_in, 315_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // turn off intake
  chassis.pid_odom_set({{-27.246_in, -16.671_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-16.671_in, -16.929_in, 40_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-11.255_in, -10.481_in, 45_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // intake on
  // end of auto


}

void ThreeBlockAutoTopRed() {
  // the start of our 15 second three block auto for bottom of the middle goal
  // setting bot pos
  chassis.odom_xyt_set(-51.747_in, 12.545_in, 50_deg);
  chassis.pid_odom_set({{-38.594_in, 23.119_in, 90_deg}, fwd, DRIVE_SPEED});
  // turning on intake
  chassis.pid_wait();
  chassis.pid_odom_set({{-21.056_in, 23.893_in, 225_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // turn off intake
  chassis.pid_odom_set({{-27.246_in, 16.671_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-16.671_in, 16.929_in, 140_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-11.255_in, 10.481_in, 135_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // intake on
  // end of auto
}

void ThreeBlockAutoBottomBlue() {
  // the start of our 15 second three block auto for bottom of the middle goal
  // setting bot pos
  chassis.odom_xyt_set(51.747_in, -12.545_in, 230_deg);
  chassis.pid_odom_set({{-38.594_in, -23.119_in, 90_deg}, fwd, DRIVE_SPEED});
  // turning on intake
  chassis.pid_wait();
  chassis.pid_odom_set({{38.594_in, -23.119_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // turn off intake
  chassis.pid_odom_set({{21.056_in, -23.893_in, 45_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{27.246_in, -16.671_in, 270_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{16.671_in, -16.929_in, 320_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // intake on
  // end of auto


}

void ThreeBlockAutoTopBlue() {
  // the start of our 15 second three block auto for bottom of the middle goal
  // setting bot pos
  chassis.odom_xyt_set(-51.747_in, 12.545_in, 50_deg);
  chassis.pid_odom_set({{-38.594_in, 23.119_in, 90_deg}, fwd, DRIVE_SPEED});
  // turning on intake
  chassis.pid_wait();
  chassis.pid_odom_set({{-21.056_in, 23.893_in, 225_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // turn off intake
  chassis.pid_odom_set({{-27.246_in, 16.671_in, 90_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-16.671_in, 16.929_in, 140_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  chassis.pid_odom_set({{-11.255_in, 10.481_in, 135_deg}, fwd, DRIVE_SPEED});
  chassis.pid_wait();
  // intake on
  // end of auto
}