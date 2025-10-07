//-----------------------------------------
// File name: IntakeControllerLib.hpp
// Creation date: 6/18/25
// Created By: Zach D (4303D Main Coder)
// Description: This is the Intake class, here you will find functions and arributes relted to our robots intake mech
//-----------------------------------------


// File includes
//--------------
#include "EZ-Template/util.hpp"
#include "pros/motors.h"
#include "RobotMechs/IntakeControllerLib.hpp"

// Intake class functions definitions
//-----------------------------------

// This function controlls the intake direction, it does this by making use of IntakeController::INTAKE_FORWARD and IntakeController::INTAKE_REVERSE.
void IntakeController::Intake::set_intake_direction(IntakeController::Direction Dir) {
    if(Dir == IntakeController::INTAKE_FORWARD) {
        IntakeController::Intake::IntakeMotorObjectA->set_reversed(false);
        IntakeController::Intake::IntakeMotorObjectB->set_reversed(false);
        // printing out the current direction of the motor
        ez::screen_print("Intake Direction: Foward", 8);

    } else if(Dir == IntakeController::INTAKE_BACKWARD) {
        IntakeController::Intake::IntakeMotorObjectA->set_reversed(true);
        IntakeController::Intake::IntakeMotorObjectB->set_reversed(true);
        // printing out the current direction of the motor
        ez::screen_print("Intake Direction: Backward", 8);
    }
}

// This function controlls the intake by making it active or inactive via a boolean called IsRunning.
void IntakeController::Intake::set_intake_status(bool IsRunning) {
    if(IsRunning == true) {
        IntakeController::Intake::IntakeMotorObjectA->move(this->DefaultIntakeSpeed);
        IntakeController::Intake::IntakeMotorObjectB->move(this->DefaultIntakeSpeed);
    } else if (IsRunning == false) {
        IntakeController::Intake::IntakeMotorObjectA->brake();
        IntakeController::Intake::IntakeMotorObjectB->brake();
    }
}