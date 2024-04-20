#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///

void stopAtWhiteLine(int lines) {
  //lines is how many lines the robot will detect before it goes too far, e.g. if we start on the goal side, the lines will likely be 2
  double whiteLineCounter = 0;  

  //Modify these values based on the light conditions on the field
  double whiteTapeReflection = 0.2;
  double tileReflection = 0.7;
  double range = (whiteTapeReflection + tileReflection)/2;

  while (true) {
    double brightness = pros::c::optical_get_brightness(21);

    if (brightness > range) {
      //on white tape
      whiteLineCounter += 1;
      if (whiteLineCounter >= lines){
        //stop the robot
        
      }
    }else if (brightness < range) {
      //on tile
      pros::delay(100);
    }else {
      master.print(0, 0, "Please check the optical sensor");
    }
    pros::delay(100);
  }
}

void default_constants() {
  chassis.pid_heading_constants_set(3, 0, 20);
  chassis.pid_drive_constants_set(20, 0.3, 90);
  chassis.pid_turn_constants_set(3, 0, 20);
  chassis.pid_swing_constants_set(5, 0, 30);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(200_ms, 3_deg, 300_ms, 7_deg, 450_ms, 450_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
}


///
// Drive Example
///
void goal_side() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches
  /*
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
  */
  // ----------- GETTING TRIBALL OUT OF MATCH LOAD ZONE ----------- //
  leftVertWing.set(true);
  chassis.pid_swing_set(ez::LEFT_SWING, -45_deg, 83, 38);
  pros::delay(100);
  leftVertWing.set(false);
  chassis.pid_wait();
  pros::delay(300);

  // ----------- PUSHING PRELOAD + MATCHLOAD TRIBALL INTO GOAL ----------- //
  chassis.pid_drive_set(-400_mm, 120);
  pros::delay(900);

  // ----------- GETTING (L) TRIBALL INFRONT OF BAR ----------- //
  chassis.pid_swing_set(ez::LEFT_SWING, 70_deg, SWING_SPEED, 8);
  chassis.pid_wait();

  chassis.pid_drive_set(1290_mm, DRIVE_SPEED);
  intake.move(120);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, 90, 4);
  chassis.pid_wait();

  //chassis.pid_drive_set(300_mm, DRIVE_SPEED);
  //chassis.pid_wait();

  // ----------- RELEASING TRIBALL TO THE FRONT OF GOAL ----------- //
  chassis.pid_swing_set(ez::LEFT_SWING, 215, SWING_SPEED, 21);
  //leftWing.set(true);
  pros::delay(700);
  intake.move(-120);
  chassis.pid_wait();

  // ----------- GETTING CENTRE TRIBALL FROM THE FRONT OF BAR ----------- //
  chassis.pid_turn_set(78_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move(120);
  pros::delay(250);

  chassis.pid_drive_set(415_mm, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(200);

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, SWING_SPEED, 3);
  chassis.pid_wait();

  // ----------- PUSHING ALL 3 TRIBALLS INTO THE GOAL ----------- //
  chassis.pid_turn_set(215_deg, TURN_SPEED);
  //chassis.pid_swing_set(ez::LEFT_SWING, 215_deg, SWING_SPEED, 2);
  leftWing.set(true);
  chassis.pid_wait();

  chassis.pid_drive_set(600_mm, DRIVE_SPEED);
  rightWing.set(true);
  pros::delay(550);
  intake.move(-120);
  pros::delay(300);
  rightWing.set(false);
  chassis.pid_wait();

  // ----------- TOUCHING THE ELEVATION BAR ----------- //
  chassis.pid_swing_set(ez::LEFT_SWING, 135_deg, SWING_SPEED, 38);
  leftWing.set(false);
  chassis.pid_wait();

  chassis.pid_drive_set(-750_mm, DRIVE_SPEED);
  pros::delay(800);
  leftVertWing.set(true);
  chassis.pid_wait();

  chassis.pid_turn_set(110_deg, TURN_SPEED);
  chassis.pid_wait();



  // chassis.pid_swing_set(ez::LEFT_SWING, 70_deg, -SWING_SPEED, 25);
  // chassis.pid_wait();
    
}

void non_goal_side() {
  const int DRIVE_SPEED = 115; 
  chassis.pid_turn_exit_condition_set(200_ms, 3_deg, 300_ms, 7_deg, 450_ms, 450_ms);
  chassis.pid_swing_exit_condition_set(200_ms, 3_deg, 200_ms, 7_deg, 250_ms, 250_ms);
  chassis.pid_drive_exit_condition_set(200_ms, 1_in, 200_ms, 3_in, 350_ms, 450_ms);
  // ----------- GETTING TRIBALL OUT OF MATCH LOAD AREA ----------- //
  chassis.pid_drive_set(230_mm, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, -45_deg, SWING_SPEED, 20);
  leftVertWing.set(true);
  pros::delay(550);
  leftVertWing.set(false);
  chassis.pid_wait();

  // ----------- PUSHING THE TRIBALL THROUGH THE HORIZONTAL ELEVATION BAR ----------- //
  chassis.pid_drive_set(-1050_mm, 110);
  backAngle.set(true);
  chassis.pid_wait();
  
  // ----------- PUSH PRELOAD INTO GOAL ----------- //
  chassis.pid_drive_set(350_mm, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 47_deg, SWING_SPEED, 5);
  chassis.pid_wait();

  chassis.pid_drive_set(1000_mm, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-5_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move(-70);

  // ----------- PUSHING CENTRE TRIBALLS OVER THE BAR ----------- //
  chassis.pid_drive_set(-180_mm, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(60_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 135_deg, SWING_SPEED, 15);
  chassis.pid_wait();

  chassis.pid_drive_set(-700_mm, DRIVE_SPEED);
  backAngle.set(false);
  pros::delay(500);
  leftWing.set(true);
  chassis.pid_wait();

  chassis.pid_drive_set(950_mm, DRIVE_SPEED);
  rightWing.set(true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 10_deg, 110, 5);
  rightWing.set(false);
  leftWing.set(false);
  chassis.pid_wait();

  chassis.pid_drive_set(-700_mm, 120);
  pros::delay(700);
  rightVertWing.set(true);
  chassis.pid_wait();

  chassis.pid_turn_set(60_deg, 120);
  chassis.pid_wait();
}

void skillsv1() {
  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, 100, 28);
  chassis.pid_wait();

  chassis.pid_drive_set(-700_mm, 123);
  pros::delay(900);

  chassis.pid_swing_set(ez::RIGHT_SWING, -65_deg, SWING_SPEED, 8);
  chassis.pid_wait();

  chassis.pid_drive_set(-370_mm, 40);
  pros::delay(1000);
  rightVertWing.set(true);
  shooter.move(95);
  pros::delay(5000);
  shooter.move(0);

  chassis.pid_swing_set(ez::RIGHT_SWING, -90_deg, SWING_SPEED, 20);
  chassis.pid_wait();

  chassis.pid_drive_set(600_mm, DRIVE_SPEED);
  rightVertWing.set(false);
  chassis.pid_wait();

  chassis.pid_turn_set(100_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, SWING_SPEED, 80);
  leftVertWing.set(true);
  rightVertWing.set(true);
  backAngle.set(true);
  pros::delay(1700);
  leftVertWing.set(false);
  rightVertWing.set(false);
  backAngle.set(false);
  chassis.pid_wait();


  chassis.pid_drive_set(-1400_mm, DRIVE_SPEED);
  pros::delay(700);
  leftVertWing.set(true);
  rightVertWing.set(true);
  chassis.pid_wait();

  chassis.pid_turn_set(105_deg, TURN_SPEED);
  chassis.pid_wait();
  
  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, SWING_SPEED, 70);
  chassis.pid_wait();

  chassis.pid_drive_set(800_mm, DRIVE_SPEED);
  pros::delay(300);
  leftVertWing.set(false);
  rightVertWing.set(false);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_drive_set(-600_mm, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(200_mm, DRIVE_SPEED);
  chassis.pid_wait();
  
  //chassis.pid_swing_set(ez::LEFT_SWING, 135_deg, SWING_SPEED, 70);
  //chassis.pid_wait();
  /*
  chassis.pid_drive_set(900_mm, DRIVE_SPEED);
  rightVertWing.set(false);
  chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -100_deg, SWING_SPEED, 45);
  
  // chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, -45_deg, SWING_SPEED, 30);
  chassis.pid_wait();

  chassis.pid_drive_set(2000_mm, 110);
  pros::delay(1200);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  leftWing.set(true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, -40_deg, SWING_SPEED, 50);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -85_deg, SWING_SPEED, 50);
  chassis.pid_wait();
  */
}
///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at
  std::cout << "turn example" << std::endl;
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .