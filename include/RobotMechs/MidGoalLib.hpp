#pragma once
//-----------------------------------------
// File name: MidGoalLib.hpp
// Creation date: 2/9/26
// Created By: Zach D (4303D Main Coder)
// Description: This lib controlls our midgoal mech and our intake a single mech
//-----------------------------------------

// File includes
//-----------------
#include "EZ-Template/piston.hpp"
#include "IntakeControllerLib.hpp"

namespace MidGoalLib {
    class MidGoalMech {
        // the main class
        public:
        ez::Piston* MidPistion;
        IntakeController::Intake* MidGoalIntake;
        // the constructor function
        MidGoalMech(ez::Piston &BotPisiton, IntakeController::Intake &BotIntake) {
            MidPistion = &BotPisiton;
            MidGoalIntake = &BotIntake;
        }

        // class functions
        // This function controls if the mech is active
        void set(bool active);
    };
}