//-----------------------------------------
// File name: IntakeControllerLib.hpp
// Creation date: 6/18/25
// Created By: Zach D (4303D Main Coder)
// Description: This is the Intake class, here you will find functions and arributes relted to our robots intake mech
//-----------------------------------------


// File includes
//--------------

#include "pros/motors.h"
#include "RobotMechs/IntakeControllerLib.hpp"

// Intake class functions definitions
//-----------------------------------

// This function controlls the intake direction, it does this by making use of IntakeController::INTAKE_FORWARD and IntakeController::INTAKE_REVERSE.
void IntakeController::Intake::set_intake_direction(IntakeController::Direction Dir) {
    if(Dir == IntakeController::INTAKE_FORWARD) {
        this->IntakeMotorObjectA->set_reversed(false);
        this->IntakeMotorObjectB->set_reversed(true);

    } else if(Dir == IntakeController::INTAKE_BACKWARD) {
        this->IntakeMotorObjectA->set_reversed(true);
        this->IntakeMotorObjectB->set_reversed(true);
    }
}

// This function controlls the intake by making it active or inactive via a boolean called IsRunning.
void IntakeController::Intake::set_intake_status(bool IsRunning) {
    if(IsRunning == true) {
        this->IntakeMotorObjectA->move_voltage(this->DefaultIntakeSpeed);
        this->IntakeMotorObjectB->move_voltage(this->DefaultIntakeSpeed);
    } else if (IsRunning == false) {
        this->IntakeMotorObjectA->brake();
        this->IntakeMotorObjectB->brake();

    }
}

// This function is like the normal set_intake_status function, but it allows a custom speed to be used instead of the default intake speed
void IntakeController::Intake::set_intake_status(bool IsRunning, const int IntakeSpeed) {
    if(IsRunning == true) {
        this->IntakeMotorObjectA->move_voltage(IntakeSpeed);
        this->IntakeMotorObjectB->move_voltage(IntakeSpeed);
    } else if (IsRunning == false) {
        this->IntakeMotorObjectA->brake();
        this->IntakeMotorObjectB->brake();
    }
}