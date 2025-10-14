//-----------------------------------------
// File name: helpers.cpp
// Creation date: 10/14/25
// Created By: Zach D (4303D Main Coder)
// Description: Thi lib will contain some helper methods to be used in code (Eg. Autonomous)
//-----------------------------------------

// File includes
// --------------
#include "EZ-Template/piston.hpp"
#include "subsystems.hpp"
#include "RobotMechs/helpers.hpp"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "RobotMechs/PistionLiftLib.hpp"
#include "pros/misc.h"

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
void driver_control_lift() {
    // Pistion lift code
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && LiftMech.get_pistion_status() == 2) {
      LiftMech.set_pistion_status(PistionLiftLib::PistionState::LIFT_UP);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && LiftMech.get_pistion_status() == 1) {
      LiftMech.set_pistion_status(PistionLiftLib::PistionState::LIFT_DOWN);
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
    } else {
        IntakeMech.set_intake_status(false);
    }
}