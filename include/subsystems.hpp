#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "RobotMechs/PistionIndexerLib.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"
#include "EZ-Template/piston.hpp"  

extern Drive chassis;


// motor defintions for mech classes
inline pros::Motor BlockIntakeMotorA(-6, pros::v5::MotorGears::blue);
inline pros::Motor BlockIntakeMotorB(-7, pros::v5::MotorGears::blue);

// our penmatics
inline ez::Piston IndxerPisiton('B', false);
inline ez::Piston MatchLoadMech('A', true); 

// mech defintions
inline IntakeController::Intake IntakeMech(BlockIntakeMotorA, BlockIntakeMotorB,120000);
inline PistionIndexerLib::PistionIndexer IndexerMech(IndxerPisiton);