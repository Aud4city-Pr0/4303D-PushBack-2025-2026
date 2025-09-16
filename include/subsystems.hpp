#pragma once

#include "EZ-Template/api.hpp"
#include "EZ-Template/tracking_wheel.hpp"
#include "api.h"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"

extern Drive chassis;


// motors, sensors and pnematic defintions for mech classes
inline pros::Motor BlockIntakeMotorA(-2, pros::v5::MotorGears::blue);
inline pros::Motor BlockIntakeMotorB(-4, pros::v5::MotorGears::blue);

// odom sensor
inline ez::tracking_wheel vertical_tracker(16, 2.0, 5.0);

// mech defintions
inline IntakeController::Intake IntakeMech(BlockIntakeMotorA, BlockIntakeMotorB, 127);