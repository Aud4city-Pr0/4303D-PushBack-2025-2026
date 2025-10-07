//-----------------------------------------
// File name: PistionLiftLib.cpp
// Creation date: 9/30/25
// Created By: Zach D (4303D Main Coder)
// Description: This lib controlls the two pistions that will lift the intake up into the scoring position
//-----------------------------------------


// File includes
//--------------
#include "RobotMechs/PistionLiftLib.hpp"
#include "EZ-Template/piston.hpp"

// Lift class function denfintions
//-----------------------------------

// this function controlls the pistion state to raise and lower it
void PistionLiftLib::PistionLift::set_pistion_status(PistionState StateToSet) {
    if (StateToSet == PistionState::LIFT_DOWN) {
        this->LiftActuator->set(true);
    } else if (StateToSet == PistionState::LIFT_UP) {
        this->LiftActuator->set(false);
    }
    PistionLiftLib::CurrentState = StateToSet;
}


// this function gets the current enum in CurrentState
int PistionLiftLib::PistionLift::get_pistion_status() {
    if(PistionLiftLib::CurrentState == PistionLiftLib::LIFT_UP) {
        return 1;
    } else if (PistionLiftLib::CurrentState == PistionLiftLib::LIFT_DOWN) {
        return 2;
    } else {
        return 0;
    }
}