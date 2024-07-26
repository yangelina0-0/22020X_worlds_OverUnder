#include "main.h"

using namespace pros;

void setIntakeTop(int topPower){
    intakeTop.move(topPower);
}

void setIntakeBottom(int bottomPower){
    intakeBottom.move(bottomPower);
}
void buttonRelease(){
    int countUp;
    int countDown;
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        countUp =+1;
    }else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == false){
        countDown =+1;
    }else if(countDown <= 3 && countUp >= 3){
        countUp = 0;
        countDown = 0;
    }

    if (countUp >= 5){
        //released
        
    }
}
int bottomPower = 125;
int topPower = 125;
void setTopIntakeMotors(){
    int intakeCounter = 1;
    //intake will only spin if the counter is on 1
    //down
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        topPower = -125;
    }
    else if (master.get_digital_new_press){
        topPower = 0;
        intakeCounter = 0;
        setIntakeTop(topPower);
        //std::cout << "in else if" << intakePower  << std::endl;    
    }
    //up
    else if (intakeCounter == 1){
        topPower = 125;
    } //stop both
    else if (master.get_digital(DIGITAL_R2)){
        topPower = 0;
        intakeCounter = 0;
    }   
    setIntakeTop(topPower);
}

void setBottomIntakeMotors(){
    int intakeCounter = 1;
    //intake will only spin if the counter is on 1
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        bottomPower = -125;
     }
    //else if (master.get_digital_new_press(DIGITAL_L2)){
    //     bottomPower = 0;
    //     intakeCounter = 0;
    //     setIntakeBottom(bottomPower);
    //     //std::cout << "in else if" << intakePower  << std::endl;    
    // }
    else if (intakeCounter == 1){
        bottomPower = 125;
    }else if (master.get_digital(DIGITAL_R2)){
        bottomPower = 0;
        intakeCounter = 0;
    }   
    setIntakeBottom(bottomPower);
}
