/* Assignment C++: 3
   Author: Ron Zilber
*/
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cstring>
using namespace std;

class Shape{
/**
 * Abstract class shape
 */
private:

protected:
    char * color{};

public:
    Shape(const Shape & otherShape);
    explicit Shape(const char * aColor);
    virtual ~Shape()=0;                                  // Pure virtual destructor to make this class an abstract class
    virtual double getPerimeter()const=0;                // Virtual function
    virtual double getArea()const=0;                     // Virtual function
    virtual void printShape(ostream&)const;              // Will have overrides at inheritance classes
    const char * getColor()const;
    friend ostream& operator<<(ostream& os, const Shape& aShape){
        aShape.printShape(os);
        return os;
    }
};
#endif //SHAPE_H
