/* Assignment C++: 3
   Author: Ron Zilber
*/
#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
class Square : public Shape{
private:
    double edgeLength;
public:
    Square(const char *, const double &); // Constructor
    Square(const Square &);               // Copy constructor
    ~Square();                            // Destructor
    void draw(ostream& os = cout) const;  // Default is to print to 'cout' (to the user). Also possible to print to given os
    virtual double getPerimeter()const;
    virtual double getArea()const;
    virtual void printShape(ostream &os)const;
    friend ostream& operator<<(ostream& os, const Square& aSquare);
    double getEdge() const;               // Returns the edge length to the user
};
#endif //SQUARE_H