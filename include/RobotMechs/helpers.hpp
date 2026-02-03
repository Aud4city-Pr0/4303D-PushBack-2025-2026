#pragma once
//-----------------------------------------
// File name: helpers.hpp
// Creation date: 10/14/25
// Created By: Zach D (4303D Main Coder)
// Description: Thi lib will contain some helper methods to be used in code (Eg. Autonomous and Driver Controll)
//-----------------------------------------

// Helper functions
// ----------------

// This function helps control the match load mech for auto
void set_match_loader_status(bool status);
// This function helps control the indexer for auto
void set_indexer_status(bool status);
// This function  controlls the wing
void set_wing_status(bool status);
// This function contains intake code for driver
void driver_control_intake();
// This function contains pistion wing code for driver
void driver_control_wing();
// This function contains pistion closer code for driver
void driver_control_closer();