// #include "main.h"

// void goToPosition(double x, double y, double movementSpeed, double preferredAngle, double turnSpeed){

//     double distanceToTarget = hypot(x - worldXPosition, y - worldYPosition);
//     //(opposite/adjacent)
//     double absAngleToTarget = atan2(y - worldYPosition, x - worldXPosition);
//     //angle 90 = forward
//     double relativeAngleToPoint  = angleWrap(absAngleToTarget - (worldAngle - toRad(90)));

//     double relativeXToPoint = cos(relativeAngleToPoint) * distanceToTarget;
//     double relativeYToPoint = sin(relativeAngleToPoint) * distanceToTarget;

//     //movement_Power will always be from 0-1
//     double movementXPower = relativeXToPoint / (abs(relativeXToPoint) + abs(relativeYToPoint));
//     double movementYPower = relativeYToPoint / (abs(relativeXToPoint) + abs(relativeYToPoint));
//     /*
//     //for the robot
//     movement_x = movementXPower*movementSpeed;
//     movement_y = movementYPower*movementSpeed;
//     */
//    //only here to prevent error code from happening when typing in the code
//     movementSpeed = movementXPower + movementYPower;

//     double relativeTurnAngle = relativeAngleToPoint - toRad(180) + preferredAngle;
//     //originally using range.clip(......) but doesn't seem to exist in c++?
//     movement_turn =  clamp(relativeTurnAngle/toRad(30), -1, 1) * turnSpeed;
//     if (distanceToTarget < 10){
//         movement_turn = 0;
//     }

// }