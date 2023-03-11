/* Assignment C++: 3
   Author: Ron Zilber
*/
#include "Menu.h"

Menu::Menu() : mainState(0), shapesState(0), shapePointersList(nullptr){} // Default Constructor

Menu::~Menu(){
    try {
        Shape *shapePointer = shapePointersList->getTop(); // Delete the dynamic memory that has been allocated in the menu
        while(shapePointer){                               // While list isn't empty
            delete shapePointer;                           // Delete the actual shape from the data field of the node
            shapePointersList->deleteNode();               // After there is no data in the node - delete that node itself
            shapePointer = shapePointersList->getTop();
        }
    }
    catch(const char * msg){}
    delete shapePointersList;                                 // After all node has been deleted - delete the list itself
}
void Menu::mainMenu(){                                       /// Final State Machine for the main menu
    shapePointersList = new LinkedList<Shape*>;               // Create an empty linked list of pointers to shapes
    bool flag = false;
    do{                                         // The flag get 'true' value when the user want to go out from this menu
        cout << "=======================================\n"
                "<1> Add element to the list\n"
                "<2> Remove the last shape from list\n"
                "<3> Print the last shape\n"
                "<4> Exit\n"
                "=======================================\n";
        cin >> mainState;                        // Get the desired option from the user
        switch (mainState) {
            case 1:{                             // Add element to the list
                shapesMenu();
                break;
            }
            case 2:{                            // Remove the last shape from list
                try{
                    delete shapePointersList->getTop();
                    shapePointersList->deleteNode();
                }
                catch(const char* msg){         // Catch an 'empty list' error
                    cout << msg << endl;
                    cout << "please try again" << endl;
                }
                break;
            }
            case 3:{ // Print the last shape
                try{
                    cout << endl;
                    cout << *(shapePointersList->getTop());
                    cout << endl;
                }
                catch(const char* msg){ // Catch an 'empty list' error
                    cout << msg << endl;
                    cout << endl; // There is also double endl in original exe file
                }
                break;
            }
            case 4:{
                cout << "goodbye!";
                flag = true;
                break;
            }
            default:{
                cout << "Invalid selection." << endl;
                break;
            }
        }
    }
    while(!flag);
}
void Menu::shapesMenu() {
    cout << "Choose 1 for Square, 2 for Circle, 3 for Triangle:";
    cin >> shapesState;
    switch (shapesState) {
        case 1: {
            insertShape("square");
            break;
        }
        case 2: {
            insertShape("circle");
            break;
        }
        case 3: {
            insertShape("triangle");
            break;
        }
        default: {
            cout << "Invalid choice" << endl;
        }
    }
}
void Menu::insertShape(const char * shape) {
    char colorBasket[20]; bool validShapeParameters = false;
    if(strcmp(shape,"square") == 0) {
        double edge;
        Square * squarePointer;
        while(!validShapeParameters){
            cout << "Enter square's color: ";
            cin >> colorBasket;
            cout << "Enter square's side length: ";
            cin >> edge;
            try {
                squarePointer = new Square(colorBasket, edge);
                validShapeParameters = true;
            }
            catch (const char *msg) {
                cout << msg << endl;
                cout << "please try again" << endl;
            }
            catch(...){cout << "unknown error occurred" << endl;}
        }
        shapePointersList->insert(squarePointer);
    }
    else if(strcmp(shape,"circle") == 0){
        double radius;
        Circle * circlePointer;
        while(!validShapeParameters){
            cout << "Enter circle's color: ";
            cin >> colorBasket;
            cout << "Enter circle's radius: ";
            cin >> radius;
            try {
                circlePointer = new Circle(colorBasket, radius);
                validShapeParameters = true;
            }
            catch (const char *msg) {
                cout << msg << endl;
                cout << "please try again" << endl;
            }
            catch(...){cout << "unknown error occurred" << endl;}
        }
        shapePointersList->insert(circlePointer);
    }
    else if(strcmp(shape,"triangle") == 0){
        double side;
        OrthogonalTriangle * trianglePointer;
        while(!validShapeParameters){
            cout << "Enter Triangle's color: ";
            cin >> colorBasket;
            cout << "Enter Triangle's side: ";
            cin >> side;
            try {
                trianglePointer = new OrthogonalTriangle(colorBasket, side);
                validShapeParameters = true;
            }
            catch (const char *msg) {
                cout << msg << endl;
                cout << "please try again" << endl;
            }
            catch(...){cout << "unknown error occurred" << endl;}
        }
        shapePointersList->insert(trianglePointer);
    }
}