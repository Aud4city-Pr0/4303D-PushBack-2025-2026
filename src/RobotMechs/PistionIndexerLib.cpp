//-----------------------------------------
// File name: PisitionIndexerLib.cpp
// Creation date: 9/30/25
// Created By: Zach D (4303D Main Coder)
// Description: This lib controlls the two pistions that will lift the intake up into the scoring position
//-----------------------------------------


// File includes
//--------------
#include "RobotMechs/PistionIndexerLib.hpp"
#include "EZ-Template/piston.hpp"

// Lift class function denfintions
//-----------------------------------

// this function controlls the pistion state to raise and lower it
void PistionIndexerLib::PistionIndexer::set_pistion_status(PistionState StateToSet) {
    if (StateToSet == PistionState::INDEXER_CLOSED) {
        this->IndexerActuator->set(false);
    } else if (StateToSet == PistionState::INDEXER_OPEN) {
        this->IndexerActuator->set(true);
    }
    PistionIndexerLib::CurrentState = StateToSet;
}


// this function gets the current enum in CurrentState
int PistionIndexerLib::PistionIndexer::get_pistion_status() {
    if(PistionIndexerLib::CurrentState == PistionIndexerLib::INDEXER_OPEN) {
        return 1;
    } else if (PistionIndexerLib::CurrentState == PistionIndexerLib::INDEXER_CLOSED) {
        return 2;
    } else {
        return 0;
    }
}