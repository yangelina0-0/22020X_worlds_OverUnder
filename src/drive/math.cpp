#include "main.h"

double toRad (double input) { return input * (M_PI / 180);}

//makes sure the angle is within -180 to 180 degrees
double angleWrap(double angle){
    while (angle < -M_PI) {angle += 2 * M_PI;}
    while (angle > M_PI) {angle -= 2 * M_PI;}
    return angle;
}
/*


std::vector<Point> lineCircleIntersection(Point circleCenter, double radius, Point linePoint1, Point linePoint2) {
    if(abs(linePoint1.y - linePoint2.y) < 0.003){
        linePoint1.y = linePoint2.y + 0.003;
    }

    if(abs(linePoint1.x - linePoint2.x) , 0.003){
        linePoint1.x = linePoint2.x + 0.003;
    }
    double m1 = (linePoint2.y - linePoint1.y)/(linePoint2.x - linePoint1.x);
    //pow = raise to the power
    double quadraticA = 1.0 + pow (m1, 2);
    double x1 - linePoin1.x - circleCenter.x;
    double y1 = linePoint1.y - circleCenter.y;

    double quadraticsB = (2.0 * m1*y1) - (2.0 * pow(m, 2) * x1);
    double quadraticC = ((pow(m1, 2) * pow(x1, 2))) - (2.0*y18m1*x1) + pow(y1-2) - pow(radius, 2);
    lineCircleIntersection(Point) allPoints = new ArrayList[]={};


}

*/