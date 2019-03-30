//
//  Node.hpp
//  cpp
//
//  Created by Crisan Alexandra on 13/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Pair
{
private:
    string key;
    int value;
    
public:
    /*
     Default constructor for a Pair
     */
    Pair(){}
    
    /*
     Constructor with parameters
     */
    Pair(string k, int v) : key(k), value(v){}
    
    /*
     Gets the key from the Pair
     Returns a string
     */
    string getKey()
    {
        return this->key;
    }
    
    /*
     Gets the value from the Pair
     Returns an integer
     */
    int getValue()
    {
        return this->value;
    }
    
    /*
     Sets the key to a given string
     input: k (string)
     output: none
     */
    void setKey(string k)
    {
        this->key = k;
    }
    
    /*
     Sets the value to a given integer
     input: v (integer)
     output: none
     */
    void setValue(int v)
    {
        this->value = v;
    }
    
    /*
     Default destructor for a Pair
     */
    ~Pair(){}
    
};

class Node
{
private:
    Pair info;
    Node* next;
    Node* prev;
    
public:
    
    /*
     Default constructor for a Node
     */
    Node(){}
    
    /*
     Constructor with parameters
     */
    Node(Pair p) : info(p), next(nullptr), prev(nullptr){}
    
    /*
     Constructor with parameters
     */
    Node(Pair p, Node* n, Node* pr) : info(p), next(n), prev(pr){}
    
    
    /*
     Gets the informatiob from the Node
     Returns a Pair
     */
    Pair getInfo()
    {
        return this->info;
    }
    
    /*
     Gets the address of the next node from the initial Node
     Returns a pointer to a Node
     */
    Node* getNext()
    {
        return this->next;
    }
    
    /*
     Gets the address of the previous node from the initial Node
     Returns a pointer to a Node
     */
    Node* getPrev()
    {
        return this->prev;
    }
    
    /*
     Sets the information to a given Pair
     input: inf (Pair)
     output: none
     */
    void setInfo(Pair inf)
    {
        this->info = inf;
    }
    
    /*
     Sets the next to a given Node*
     input: n (pointer to a Node)
     output: none
     */
    void setNext(Node * n)
    {
        this->next = n;
    }
    
    /*
     Sets the previous to a given Node*
     input: p (pointer to a Node)
     output: none
     */
    void setPrev(Node * p)
    {
        this->prev = p;
    }
    
    /*
     Method for printing a Pair
     */
    void toString()
    {
        cout<<"Name: "<<this->getInfo().getKey()<<" Number of pieces: "<< this->getInfo().getValue()<<endl;
    }
    
    /*
     Default destructor for a Node
     */
    ~Node() {}
};

#endif /* Node_hpp */
