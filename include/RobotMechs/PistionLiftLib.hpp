#pragma once
//-----------------------------------------
// File name: PistionLiftLib.hpp
// Creation date: 9/30/25
// Created By: Zach D (4303D Main Coder)
// Description: This lib controlls the two pistions that will lift the intake up into the scoring position
//-----------------------------------------

// File includes
//-----------------
#include "EZ-Template/piston.hpp"


// The pistion lift class
namespace PistionLiftLib {
    // pistion state enum
    enum PistionState {
        LIFT_DOWN = 0,
        LIFT_UP = 1
    };
    inline PistionState CurrentState;

    // pistion lift class
    class PistionLift {
        public:
        ez::Piston* LiftActuator;
        PistionLift(ez::Piston LiftPistionActuator) {
            LiftActuator = &LiftPistionActuator;
        }
        // pisiton lift class functions
        void set_pistion_status(PistionState StateToSet);
        PistionState get_pistion_staus();

    };
}
