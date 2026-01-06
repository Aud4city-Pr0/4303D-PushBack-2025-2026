//-----------------------------------------
// File name: helpers.cpp
// Creation date: 10/14/25
// Created By: Zach D (4303D Main Coder)
// Description: Thi lib will contain some helper methods to be used in code (Eg. Autonomous)
//-----------------------------------------

// File includes
// --------------
#include "EZ-Template/piston.hpp"
#include "EZ-Template/util.hpp"
#include "subsystems.hpp"
#include "RobotMechs/helpers.hpp"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "RobotMechs/PistionIndexerLib.hpp"
#include "pros/misc.h"

// Helper vars
// ------------
bool Scorestatus = false;

// Helper functions
// ----------------

// This function helps control the match load mech for auto
void set_match_loader_status(bool status) {
    if(status == true && MatchLoadMech.get() == false) {
        MatchLoadMech.set(true);
    } else if(status == false && MatchLoadMech.get() == true) {
        MatchLoadMech.set(false);
    }
}

// This is driver control code for our lift
void driver_control_indexer() {
    // Pistion lift code
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && IndexerMech.get_pistion_status() == 2) {
      IndexerMech.set_pistion_status(PistionIndexerLib::PistionState::INDEXER_OPEN);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && IndexerMech.get_pistion_status() == 1) {
      IndexerMech.set_pistion_status(PistionIndexerLib::PistionState::INDEXER_CLOSED);
    }
}

// This is driver control code for our intake
void driver_control_intake() {
    // intake controll code
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      IntakeMech.set_intake_direction(IntakeController::INTAKE_FORWARD);
      IntakeMech.set_intake_status(true);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      IntakeMech.set_intake_direction(IntakeController::INTAKE_BACKWARD);
      IntakeMech.set_intake_status(true);
    } else {
      IntakeMech.set_intake_status(false);
    }
}