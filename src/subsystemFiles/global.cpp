#include "main.h"
//Motors
pros::Motor intakeLeft(9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intakeRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor_Group intake({intakeLeft, intakeRight});
pros:: Motor shooter(16, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

//sensors
pros::ADIPotentiometer potentiometer('A');
pros:: Optical optical(21);

//pneumatics
ez::Piston rightWing('A');
ez::Piston leftWing('B');
ez::Piston backAngle('F', 2, false);
//pros::ADIDigitalOut backAngle ({{2, 'F'}});
ez::Piston rightVertWing('D');
ez::Piston leftVertWing('E');
ez::Piston rightHang('C', 2, false);
ez::Piston leftHang('G', 2, false);
ez::Piston midHang('H', 2, false);

