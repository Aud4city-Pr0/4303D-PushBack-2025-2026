#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"

extern Drive chassis;

// motors, sensors and pnematic defintions for mech classes
pros::Motor BlockIntakeMotorA(-2, pros::v5::MotorGears::blue);
pros::Motor BlockIntakeMotorB(-4, pros::v5::MotorGears::blue);

// mech defintions
inline IntakeController::Intake IntakeMech(BlockIntakeMotorA, BlockIntakeMotorB, 127);