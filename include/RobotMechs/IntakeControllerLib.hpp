#pragma once
//-----------------------------------------
// File name: IntakeControllerLib.hpp
// Creation date: 6/18/25
// Created By: Zach D (4303D Main Coder)
// Last updated: 6/19/25
// Description: This is the Intake class, here you will find functions and arributes relted to our robots intake mech
//-----------------------------------------


// File includes
//--------------
#include "api.h"
#include "pros/motors.h"

// The IntakeController Lib
namespace IntakeController {
    // The intake direction enum
    enum Direction {
      INTAKE_FORWARD = 0,
      INTAKE_BACKWARD = 1,
    };
    class Intake
    {
        public:
        pros::Motor* IntakeMotorObject;
        int DefaultIntakeSpeed;
        // This is the intake classes constructor function, it takes in a motor and an int that ranges from 0-127.
        Intake(pros::Motor IntakeMotor, const int IntakeSpeed) {
          IntakeMotorObject = &IntakeMotor;
          DefaultIntakeSpeed = IntakeSpeed;
        }
        // The intake functions
        void set_intake_status(bool IsRunning);
        void set_intake_direction(Direction IntakeDir);
    };
}
