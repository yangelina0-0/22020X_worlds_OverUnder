#include "main.h"
#define lWing 'A'
#define rWing 'B'
#define lVWing 'C'
#define rVWing 'D'
void initialize() {
  pros::ADIDigitalOut leftWing (lWing);
  pros::ADIDigitalOut rightWing (rWing);
  pros::ADIDigitalOut leftVertWing (lVWing);
  pros::ADIDigitalOut rightVertWing (rVWing);
}

