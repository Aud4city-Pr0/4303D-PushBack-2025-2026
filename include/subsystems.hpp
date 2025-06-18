#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "RobotMechs/IntakeControllerLib.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motors.hpp"

extern Drive chassis;

// These are the actual motors, pistions and sensors of our robot
pros::Motor BlockIntakeMotor(2, pros::v5::MotorGears::blue);

// This is the IntakeController
inline IntakeController::Intake IntakeMech(BlockIntakeMotor, 127);