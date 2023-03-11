/* Assignment C++: 3
   Author: Ron Zilbershtein, ID: 205996929
*/
#include "Circle.h"

Circle::Circle(const char *aColor, const double &aRadius):Shape(aColor){
    if(aRadius<0) {
        //delete color;
        throw "Exception: The radius must be positive!";
    }
    radius = aRadius;
}

Circle:: Circle(const Circle & otherCircle):Shape(otherCircle.getColor()){ // Copy constructor
    radius = otherCircle.radius;
}

Circle:: ~Circle()= default;

double Circle::getArea()const { return pi*radius*radius;}

double Circle::getPerimeter()const {return 2*pi*radius;}

double Circle:: getRadius()const{return radius;}

void Circle::printShape(ostream &os) const {
    os << "Circle details: color=" << color << " ,radius="
       << radius << endl;
    os << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;
}




