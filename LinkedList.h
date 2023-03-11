/* Assignment C++: 3
   Author: Ron Zilber
*/
#ifndef PROJECT3_LINKEDLIST_H
#define PROJECT3_LINKEDLIST_H
#include "Node.h"
#include <typeinfo>
/**
 * A template Linked List implementation using class Node objects
 */
template <class T>
class LinkedList{
private:
    Node<T> * head; // A pointer to the first node in the linked list
    int nodesCount;
public:
    LinkedList():head(nullptr), nodesCount(0){}// The default constructor
    ~LinkedList(){                                           // Destructor
        while(nodesCount>0) deleteNode();                    // while the linked list isn't empty - delete the next node
    }
    void insert(const T& aData){                             // Insert a node to the list
        Node<T>* temp = head;
        head = new Node<T>(aData);
        head->setNext(temp);
        nodesCount++;
    }
    T deleteNode(){                                          // Delete the head of the list
        if(nodesCount==0) throw "Exception: The List is empty!";
        //Otherwise (list isn't empty):
        Node<T>* temp = head;
        T tempData = temp->getData();
        head = head->getNext();
        delete temp;
        nodesCount--;
        return tempData;
    }
    T deleteNode(const T& aData){                           // Delete an object by given data
        if(nodesCount==0) throw "Exception: The List is empty!";
        if(head->getData() == aData){                       // Check the first node (The head)
            deleteNode();                                   // Delete the head
            return aData;
        }
       Node<T>  *prevNode = head, *currNode = head->getNext();
       while(currNode){                          // When reached to the bottom of the linked list, currNode will be NULL
           if(currNode->getData() == aData){
               prevNode->setNext(currNode->getNext()); // Connect the two nodes before and after the one that we delete
               delete currNode;
               nodesCount--;
               return aData;
           }
           prevNode = currNode; currNode = currNode->getNext();  // Point the nodes one step deeper into the linked list
       }
       throw "Element not found"; // TODO: ask Or about the message to throw here
    }
    bool search(const T& aData){                                 // Search for a node by given data
        Node<T>* temp = head;
        while(temp){                                             // Until the list bottom has reached (null ptr)
            if(temp->getData()==aData)return true;
            temp = temp->getNext();
            }
        return false;
        }
    const T& getTop()const{                                      // Returns the data of the head node
        if(nodesCount==0){
            throw "Exception: List is empty!";
        }
        else{
            return head->getData();
            }
    }
    friend ostream& operator<<(ostream& os, const LinkedList<T>& aList){ // Printing operator
        if(aList.nodesCount==0) {
            throw "Exception: List is empty!";
        }
        Node<T>* currNode = aList.head;
        os << endl;
        while(currNode){
                os << (currNode->getData()) << endl;
                currNode = currNode->getNext();
        }
        return os;
    }
};
#endif //PROJECT3_LINKEDLIST_H
