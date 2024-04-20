#include "main.h"
#include "autons.hpp"
void autonSelect(double selectedValue){
    //std::cout << "potentiometer reading" << selectedValue << std::endl;
    if (selectedValue >0 && selectedValue < 880){
        std::cout << "selected autonomous number 1" << std::endl;
        //goal side auton 1
    }else if (selectedValue > 881 && selectedValue < 1780){
        std::cout << "selected autonomous number 2" << std::endl;
        //goal side auton 2
    }else if (selectedValue > 1781 && selectedValue < 2890){
        std::cout << "selected autonomous number 3" << std::endl;
        //goal side auton 3
    }else if (selectedValue > 2891 && selectedValue < 4095){
        std::cout << "selected autonomous number 4" << std::endl;
        //goal side auton 4
    }else{
        std::cout << "ERROR" << std::endl;
    }
}