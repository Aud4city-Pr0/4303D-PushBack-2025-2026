//-----------------------------------------
// File name: helpers.cpp
// Creation date: 10/14/25
// Created By: Zach D (4303D Main Coder)
// Description: Thi lib will contain some helper methods to be used in code (Eg. Autonomous)
//-----------------------------------------

// File includes
// --------------
#include "EZ-Template/piston.hpp"
#include "subsystems.hpp"
#include "RobotMechs/helpers.hpp"

// Helper functions
// ----------------

// This function helps control the match load mech for auto
void set_match_loader_status(bool status) {
    if(status == true && MatchLoadMech.get() == false) {
        MatchLoadMech.set(true);
    } else if(status == false && MatchLoadMech.get() == true) {
        MatchLoadMech.set(false);
    }
}