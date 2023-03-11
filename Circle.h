/* Assignment C++: 3
   Author: Ron Zilbershtein, ID: 205996929
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#define pi 3.14159265358979323846264338327

class Circle: public Shape{
private:
    double radius;

public:
    Circle(const char *, const double &);               // Constructor
    Circle(const Circle &);                             // Copy constructor
    ~Circle();
    virtual double getPerimeter()const;
    virtual double getArea()const;
    double getRadius() const;                          // Returns the radius to the user
    virtual void printShape(ostream &os)const;
};
#endif //CIRCLE_H
