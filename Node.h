/* Assignment C++: 3
   Author: Ron Zilber
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <class T>
class Node{
private:
    T data;
    Node<T> * next;                                                 // Pointer to the next node

public:
    explicit Node():next(nullptr), data(nullptr){}                  // Default constructor
    explicit Node(T aData):next(nullptr),data(aData){}              // Constructor with argument
    Node(Node<T>& otherNode):next(nullptr){                         // Copy constructor
        data = otherNode.data;
    }

    Node<T>& operator =(const Node<T> & otherNode) {                // Deep copy the argument node to the operating node
        if (this != &otherNode) {                                   // Prevent auto assignment
            data = otherNode.data;
        }
    }
    ~Node() = default;                                              // The default destructor

    const T& getData()const{                                        // Returns the data of the operating node
        return data;
    }
    Node<T>* getNext()const{                                        // Returns a pointer to the next node
        return next;
    }

    void setNext(Node<T>* nextNodePointer){                       // Sets a pointer to the next node
        next = nextNodePointer;
    }
};
#endif //NODE_H