//-----------------------------------------
// File name: MidGoalLib.cpp
// Creation date: 2/9/26
// Created By: Zach D (4303D Main Coder)
// Description: This lib controlls our midgoal mech and our intake a single mech
//-----------------------------------------

// File includes
//-----------------
#include "EZ-Template/piston.hpp"
#include "IntakeControllerLib.hpp"
#include "RobotMechs/MidGoalLib.hpp"

// functions
void MidGoalLib::MidGoalMech::set_active(bool active) {
    if(active == false && MidGoalMech::MidPistion->get() == true) {
        IntakeObject->set_intake_direction(IntakeController::INTAKE_FORWARD);
        MidPistion->set(true);
        IntakeObject->set_intake_status(true, 4500);
    } else if(active == true && MidGoalMech::MidPistion->get() == false) {
        IntakeObject->set_intake_direction(IntakeController::INTAKE_FORWARD);
        MidPistion->set(false);
        IntakeObject->set_intake_status(false);
    }
}