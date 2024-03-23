#include "main.h"

//Motors
pros::Motor intakeLeft(7, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intakeRight(8, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//pneumatics
ez::Piston leftWing('A');
ez::Piston rightWing('B');
ez::Piston leftVertWing('C');
ez::Piston rightVertWing('D');