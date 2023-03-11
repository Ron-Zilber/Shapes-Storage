/* Assignment C++: 3
   Author: Ron Zilber
*/

#include "Square.h"

Square::Square(const char *aColor, const double &aEdge):Shape(aColor){
    if(aEdge<0) {
        //delete color;
        throw "Exception: The side must be positive";
    }
    edgeLength = aEdge;
        }

Square:: Square(const Square & otherSquare):Shape(otherSquare.getColor()){
    edgeLength = otherSquare.edgeLength;
}

Square:: ~Square()= default;

double Square::getArea()const { return edgeLength*edgeLength;}

double Square::getPerimeter()const {return 4*edgeLength;}
double Square::getEdge()const {return edgeLength;}

void Square::draw(ostream& os) const {
        for(int i = 1;i<=edgeLength;i++){
        for(int j=1;j<=edgeLength;j++){
            os << " *";
        }
        os << endl;
    }
}
ostream& operator<<(ostream& os, const Square& aSquare){
    os << "Square details: color=" << aSquare.getColor() <<", side length=" << aSquare.getEdge()<< endl;
    os << "area= " << aSquare.getArea() << ", perimeter=" << aSquare.getPerimeter() << endl;
    aSquare.draw(os);
    return os;
}
void Square::printShape(ostream& os)const{
    os << "Square details: color=" << getColor() <<", side length=" << edgeLength<< endl;
    os << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;
    this->draw(os);
}