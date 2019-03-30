//
//  Iterator.hpp
//  cpp
//
//  Created by Crisan Alexandra on 15/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>
#include "Node.hpp"
#include "DLLMap.hpp"

class Iterator
{
private:
    Node* currentNode;
    DLL &list;
    
public:
    
    /*
     Constructor with parameters
     */
    Iterator(DLL &l) : list(l)
    {
        this->currentNode = this->list.getHead();
    }
    
    /*
     Gets the current Node from the Iterator
     Returns a pointer to a Node
     */
    Node* getCurrent()
    {
        return this->currentNode;
    }
    
    /*
     Sets the Iterator to the head of the list
     */
    void setFirst()
    {
        this->currentNode = this->list.getHead();
    }
    
    /*
     Sets the Iterator to the tail of the list
     */
    void setLast()
    {
        this->currentNode = this->list.getTail();
    }
    
    /*
     Moves the iterator to the next element in the list
     */
    void next()
    {
        this->currentNode = this->currentNode->getNext();
    }
    
    /*
     Moves the iterator to the previous element in the list
     */
    void previous()
    {
        this->currentNode = this->currentNode->getPrev();
    }
    
    /*
     Checks if the current element is valid
     Returns true if it is, false otherwise
     */
    bool valid()
    {
        if (this->currentNode == NULL)
            return false;
        return true;
    }
    
    /*
     Default destructor for an Iterator
     */
    ~Iterator(){}
};

#endif /* Iterator_hpp */
