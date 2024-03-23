#include "main.h"

void setIntake(int power){
    intakeLeft.move(power);
    intakeRight.move(power);
}
int intakePower = 125;
int intakeCounter = 1;
void setIntakeMotors(){
    //intake will only spin if the counter is on 1
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakePower = -125;
        intakeCounter = 1;
    }else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intakeCounter = 0;
        intakePower = 0;
        setIntake(intakePower);
        
        //std::cout << "in else if" << intakePower  << std::endl;    
    }else if (intakeCounter == 1){
        intakePower = 125;
    }   
    
    setIntake(intakePower);
}
