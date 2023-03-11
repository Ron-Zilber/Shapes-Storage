/* Assignment C++: 3
   Author: Ron Zilber
*/
#ifndef MENU_H
#define MENU_H
#include "Square.h"
#include "OrthogonalTriangle.h"
#include "Circle.h"
#include "LinkedList.h"
#include <cstring>

class Menu{                         // Operates as a user interface
private:
    int mainState, shapesState;
    void shapesMenu();
    void insertShape(const char *);
    LinkedList<Shape*> * shapePointersList;

public:
    explicit Menu();                // The default constructor
    void mainMenu();                // User interface built as a Final State Machine
    ~Menu();                        // Destructor
};
#endif //MENU_H