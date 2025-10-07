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
#include "EZ-Template/util.hpp"

// Lift class function denfintions
//-----------------------------------

// this function controlls the pistion state to raise and lower it
void PistionLiftLib::PistionLift::set_pistion_status(PistionState StateToSet) {
    if (StateToSet == PistionState::LIFT_DOWN) {
        this->LiftActuator->set(false);
        ez::screen_print("Pistion Direction: DOWN", 9);
    } else if (StateToSet == PistionState::LIFT_UP) {
        this->LiftActuator->set(true);
        ez::screen_print("Pistion Direction: UP", 9);
    }
    PistionLiftLib::CurrentState = StateToSet;
}


// this function gets the current enum in CurrentState
bool PistionLiftLib::PistionLift::get_pistion_status() {
    if(PistionLiftLib::CurrentState == PistionState::LIFT_DOWN) {
        return false; 
    } else if(PistionLiftLib::CurrentState == PistionState::LIFT_UP) {
        return true;
    } else {
        return false;
    }
}