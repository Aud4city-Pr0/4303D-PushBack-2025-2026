#pragma once
//-----------------------------------------
// File name: PisitionIndexerLib.hpp
// Creation date: 9/30/25
// Created By: Zach D (4303D Main Coder)
// Description: This lib controlls the two pistions that will lift the intake up into the scoring position
//-----------------------------------------

// File includes
//-----------------
#include "EZ-Template/piston.hpp"


// The pistion lift class
namespace PistionIndexerLib {
    // pistion state enum
    enum PistionState {
        INDEXER_OPEN = 0,
        INDEXER_CLOSED = 1
    };
    inline PistionState CurrentState;

    // pistion lift class
    class PistionIndexer {
        public:
        ez::Piston* IndexerActuator;
        PistionIndexer(ez::Piston &PistionActuator) {
            IndexerActuator = &PistionActuator;
        }
        // pisiton lift class functions
        void set_pistion_status(PistionState StateToSet);
        int get_pistion_status();

    };
}
