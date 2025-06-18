#pragma once
//-----------------------------------------
// File name: IntakeControllerLib.hpp
// Creation date: 6/18/25
// Created By: Zach D (4303D Main Coder)
// Last updated: 6/18/25
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
        pros::Motor IntakeMotorObject;
        int DefaultIntakeSpeed;
        // The intake functions
        Intake(pros::Motor IntakeMotor, const int MotorDefualtSpeed) {
         IntakeMotorObject = IntakeMotor;
         DefaultIntakeSpeed = MotorDefualtSpeed;
        }
        void set_intake_status(bool IsRunning);
        void set_intake_direction(Direction IntakeDir);
   };
}
