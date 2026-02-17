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
void MidGoalLib::MidGoalMech::set(bool active) {
    if(active == false) {
        MidPistion->set(false);
    } else if(active == true) {
        MidPistion->set(true);
    }
}