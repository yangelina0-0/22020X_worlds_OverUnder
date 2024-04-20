#include "main.h"

using namespace pros;

// void shoot (){
//     bool shooterMove = false;
//     if (master.get_digital(DIGITAL_X)){
//         if (!shooterMove){
//             shooter.move(80);
//             shooterMove = true;
//         }else if (shooterMove){
//             shooter.move(0);
//             shooterMove = false;
//         }
//     }else{
//         pros::delay(100);
//     }
// }
void shoot (){
    static bool toggle { false };
    if (master.get_digital_new_press(DIGITAL_X)) {
        if (!toggle) {
            shooter.move(95);
            toggle = !toggle;
        }
        else {
            shooter.move(0);
            toggle = !toggle;
        }
    }
}
