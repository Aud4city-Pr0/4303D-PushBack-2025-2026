#pragma once

#include "EZ-Template/api.hpp"
#include "EZ-Template/tracking_wheel.hpp"
#include "api.h"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "RobotMechs/PistionLiftLib.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"
#include "EZ-Template/piston.hpp"

extern Drive chassis;


// motors, sensors and pnematic defintions for mech classes
inline pros::Motor BlockIntakeMotorA(-4, pros::v5::MotorGears::blue);
inline pros::Motor BlockIntakeMotorB(7, pros::v5::MotorGears::blue);
inline ez::Piston LiftPisiton('A', false);
inline ez::Piston MatchLoadMech('B', false);

// odom sensor
inline ez::tracking_wheel vertical_tracker(16, 2.0, 5.0);

// mech defintions
inline IntakeController::Intake IntakeMech(BlockIntakeMotorA, BlockIntakeMotorB, 127);
inline PistionLiftLib::PistionLift LiftMech(LiftPisiton);