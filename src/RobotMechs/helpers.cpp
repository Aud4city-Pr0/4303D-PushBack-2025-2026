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
#include "RobotMechs/MidGoalLib.hpp"
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

// This function helps control the wing mech for auto
void set_wing_status(bool status) {
  if(status == true && WingMech.get() == false) {
    WingMech.set(true);
  } else if(status == false && WingMech.get() == true) {
    WingMech.set(false);
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
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      MidMech.set(true);
    } else {
      MidMech.set(false);
      IntakeMech.set_intake_status(false);
    }
}

// Driver controll code for wing mech
void driver_control_wing() {
  if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == true) {
    WingMech.set(true);
  } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == false) {
    WingMech.set(false);
  }
}

// Driver controll code for closer mech
void driver_control_closer() {
  if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == true) {
    IndxerPisiton.set(true);
  } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == false) {
    IndxerPisiton.set(false);
  }
}