//-----------------------------------------
// File name: IntakeControllerLib.hpp
// Creation date: 6/18/25
// Created By: Zach D (4303D Main Coder)
// Last updated: 6/18/25
// Description: This is the Intake class, here you will find functions and arributes relted to our robots intake mech
//-----------------------------------------


// File includes
//--------------
#include "pros/motors.hpp"
#include "RobotMechs/IntakeControllerLib.hpp"
// This function controlls the intake direction
void IntakeController::Intake::set_intake_direction(IntakeController::Direction Dir) {
    if(Dir == IntakeController::INTAKE_FORWARD) {
        this->IntakeMotorObject.set_reversed(false);
    } else if(Dir == IntakeController::INTAKE_BACKWARD) {
        this->IntakeMotorObject.set_reversed(true);
    }
}

// This function controlls the intake 
void IntakeController::Intake::set_intake_status(bool IsRunning) {
    if(IsRunning == true) {
        this->IntakeMotorObject.move(this->DefaultIntakeSpeed);
    } else if (IsRunning == false) {
        this->IntakeMotorObject.brake();
    }
}