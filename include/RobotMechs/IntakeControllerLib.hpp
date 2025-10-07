#pragma once
//-----------------------------------------
// File name: IntakeControllerLib.hpp
// Creation date: 6/18/25
// Created By: Zach D (4303D Main Coder)
// Description: This is the Intake class, here you will find functions and arributes relted to our robots intake mech
//-----------------------------------------


// File includes
//--------------
#include "api.h"
#include "pros/motors.hpp"

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
        pros::Motor* IntakeMotorObjectA;
        pros::Motor* IntakeMotorObjectB;
        int DefaultIntakeSpeed;
        // This is the intake classes constructor function, it takes in a motor and an int that ranges from 0-127.
        Intake(pros::Motor &IntakeMotorA, pros::Motor &IntakeMotorB, const int IntakeSpeed) {
          IntakeMotorObjectA = &IntakeMotorA;
          IntakeMotorObjectB = &IntakeMotorB;
          DefaultIntakeSpeed = IntakeSpeed;
        }
        // The intake functions
        void set_intake_status(bool IsRunning);
        void set_intake_direction(Direction IntakeDir);
    };
};
