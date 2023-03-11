/* Assignment C++: 3
   Author: Ron Zilber
*/

#include "OrthogonalTriangle.h"

OrthogonalTriangle::OrthogonalTriangle(const char *aColor, const double &aSide):Shape(aColor){
    if(aSide<0) {
        throw "Exception: The side must be positive";
    }
    side = aSide;
}
OrthogonalTriangle:: OrthogonalTriangle(const OrthogonalTriangle & otherTriangle):Shape(otherTriangle.getColor()){
    side = otherTriangle.side;
}

OrthogonalTriangle:: ~OrthogonalTriangle()= default; // No memory allocating so default dtor

double OrthogonalTriangle::getArea()const { return side*side*0.5;}

double OrthogonalTriangle::getPerimeter()const {return (2+sqrt2)*side;}

void OrthogonalTriangle::draw(ostream& os)const {
    for(int i = 1;i<=side;i++){
    for(int j=1;j<=i;j++){
        os << " *";
    }
    os << endl;
}
}
void OrthogonalTriangle::printShape(ostream& os)const{
    os << "OrthogonalTriangle details: color=" << getColor() <<", side=" << side << endl;
    os << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;
    this->draw(os);
}