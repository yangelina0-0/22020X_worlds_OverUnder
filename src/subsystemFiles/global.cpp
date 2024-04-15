#include "main.h"

//Motors
pros::Motor intakeLeft(9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intakeRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor_Group intake({intakeLeft, intakeRight});

pros:: ADIPotentiometer potentiometer('H');
pros:: Optical optical(21);
//pneumatics
ez::Piston leftWing('B');
ez::Piston rightWing('A');
//ez::Piston leftVertWing('C');
//ez::Piston rightVertWing('D');
ez::Piston backAngle('C');
ez::Piston rightVertWing('D');
ez::Piston leftVertWing('E');
ez::Piston leftHang('F');
ez::Piston rightHang('G');

