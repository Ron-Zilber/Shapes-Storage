/* Assignment C++: 3
   Author: Ron Zilber
*/

#ifndef ORTHOGONALTRIANGLE_H
#define ORTHOGONALTRIANGLE_H
#include "Shape.h"
#define sqrt2 1.41421356 // sqrt (2)

class OrthogonalTriangle: public Shape{
private:
        double side;

public:
    OrthogonalTriangle(const char *, const double &); // Constructor
    OrthogonalTriangle(const OrthogonalTriangle &);   // Copy constructor
    ~OrthogonalTriangle();                            // Destructor
    virtual double getPerimeter()const;
    virtual double getArea()const;
    void draw(ostream& os = cout)const;
    virtual void printShape(ostream &os) const;
};
#endif //ORTHOGONALTRIANGLE_H