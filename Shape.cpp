/* Assignment C++: 3
   Author: Ron Zilber
*/
#include "Shape.h"
Shape::Shape(const char * aColor){
        if(strcmp(aColor,"red")!=0 && strcmp(aColor,"green")!=0 && strcmp(aColor,"blue")!=0)
            throw "Exception: color must be red green or blue";
        else{
            color = new char[sizeof(aColor)];
            strcpy(color,aColor);
    }
}
Shape::Shape(const Shape & otherShape){ // Copy constructor
    if(strcmp(otherShape.getColor(),"red")!=0 && strcmp(otherShape.getColor(),"green")!=0 && strcmp(otherShape.getColor(),"blue")!=0)
        throw "Exception: color must be red green or blue";
    else{
        color = new char[sizeof(otherShape.getColor())];
        strcpy(color,otherShape.getColor());
    }
}
Shape::~Shape(){
    delete color;
}
const char * Shape:: getColor()const{
    return color;
}

void Shape::printShape(ostream&)const{cout << color;}
// Redefined in Square, Circle & OrthogonalTriangle classes