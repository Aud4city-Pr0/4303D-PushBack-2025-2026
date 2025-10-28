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


// motor defintions for mech classes
inline pros::Motor BlockIntakeMotorA(-4, pros::v5::MotorGears::blue);
inline pros::Motor BlockIntakeMotorB(5, pros::v5::MotorGears::green);
inline pros::Motor BlockIntakeMotorC(-6, pros::v5::MotorGears::green);

// our penmatics
inline ez::Piston LiftPisiton('A', false);
inline ez::Piston MatchLoadMech('B', false);
inline ez::Piston IndexerPistion('D', true);

// mech defintions
inline IntakeController::Intake IntakeMech(BlockIntakeMotorA, BlockIntakeMotorB, 120000);
inline PistionLiftLib::PistionLift LiftMech(LiftPisiton);