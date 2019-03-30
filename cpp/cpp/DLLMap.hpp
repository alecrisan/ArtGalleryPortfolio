//
//  DLLMap.hpp
//  cpp
//
//  Created by Crisan Alexandra on 13/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef DLLMap_hpp
#define DLLMap_hpp

#include <stdio.h>
#include <iostream>
#include "Node.hpp"
#include "Exception.h"
#include <string.h>
#include <vector>

using namespace std;

class DLL
{
private:
    Node* head;
    Node* tail;
    int relation(string a, string b)
    {
        if (a.compare(b) < 0)
            return 1;
        return 0;
    }
    
    
public:
    /*
     Default constructor for a DLL
     */
    DLL(): head(nullptr), tail(nullptr) {}
    
    /*
     Gets the head of the list
     Returns a pointer to a Node
     */
    Node* getHead()
    {
        return this->head;
    }
    
    /*
     Gets the tail of the list
     Returns a pointer to a Node
     */
    Node* getTail()
    {
        return this->tail;
    }
    
    /*
     Sets the head of the list to a given Node*
     input: h (pointer to a Node)
     output: none
     */
    void setHead(Node *h)
    {
        this->head = h;
    }
    
    /*
     Sets the tail of the list to a given Node*
     input: t (pointer to a Node)
     output: none
     */
    void setTail(Node *t)
    {
        this->tail = t;
    }
    
    /*
     Searches through the list for an element with a given key
     input: key (string)
     output: pointer to a Node (NULL if it wasn't found)
     */
    Node* search(const string & key)
    {
        Node* currentNode = this->head;
        bool found = false;
        while (currentNode != NULL && found == false) {
            if (currentNode->getInfo().getKey() == key)
                found = true;
            else
                currentNode = currentNode->getNext();
        }
        
        if (found)
            return currentNode;
        else
            return NULL;
    }
    
    /*
     Adds a new Node to the list (with a given key and value)
     input: key (string)
            value (integer)
     output: none
            throws an exception if there already exists a Pair with the same key
     */
    void add(const string & key, const int & value)
    {
        int ok = 0;
        Node* find = this->search(key);
        if (find != NULL)
            throw Exception("The artist is already in the list");
        
        Node* currentNode = this->head;
        
        if(currentNode == NULL)
        {
            //the list is empty
            Node *toAdd = new Node;
            toAdd->setInfo(Pair(key, value));
            toAdd->setNext(nullptr);
            toAdd->setPrev(nullptr);
            this->setHead(toAdd);
            this->setTail(toAdd);
            return;
        }
        
        //insert it first
        if(this->relation(currentNode->getInfo().getKey(), key) == 0)
        {
            Node *toAdd = new Node;
            toAdd->setInfo(Pair(key, value));
            toAdd->setNext(currentNode);
            currentNode->setPrev(toAdd);
            toAdd->setPrev(nullptr);
            this->setHead(toAdd);
            ok = 1;
        }
        
        while(currentNode != NULL && ok == 0)
        {
            //the list is not empty
            if(currentNode->getNext() != NULL)
            {
                //it has more than one element
            
                if(this->relation(currentNode->getNext()->getInfo().getKey(), key) == 0 && this->relation(currentNode->getInfo().getKey(), key) == 1)
                {
                    Node *toAdd = new Node;
                    toAdd->setInfo(Pair(key, value));
                    toAdd->setNext(currentNode->getNext());
                    currentNode->setNext(toAdd);
                    toAdd->getNext()->setPrev(toAdd);
                    toAdd->setPrev(currentNode);
                    ok = 1;
                    currentNode = currentNode->getNext();
                }

            }
            else
            {
                //it has only one element
                
                if(this->relation(currentNode->getInfo().getKey(), key) == 1)
                {
                    //we insert it after
                    Node *toAdd = new Node;
                    toAdd->setInfo(Pair(key, value));
                    toAdd->setNext(nullptr);
                    currentNode->setNext(toAdd);
                    toAdd->setPrev(currentNode);
                    this->setTail(toAdd);
                    ok = 1;
                    currentNode = currentNode->getNext();
                }
                else
                {   //we insert it before
                    Node *toAdd = new Node;
                    toAdd->setInfo(Pair(key, value));
                    toAdd->setNext(currentNode);
                    currentNode->setPrev(toAdd);
                    toAdd->setPrev(nullptr);
                    this->setHead(toAdd);
                    ok = 1;
                    currentNode = currentNode->getNext();
                }
                
            }
            currentNode = currentNode->getNext();
            
        }
        
    }
    
    /*
     Deletes a Node from the list (with a given key)
     input: key (string)
     output: none
     throws an exception if there is no Pair with the given key
     */
    void del(string key)
    {
        Node* find = this->search(key);
        if (find == NULL)
            throw Exception("Artist not found!");
        
        Node* currentNode = this->head;
        
        
        if(currentNode == find)
        {
            //the first element is the searched one
            if(currentNode->getNext() == NULL)
            {
                //it's the only element in the list
                this->setHead(nullptr);
                this->setTail(nullptr);
                delete find;
                return;
            }
            else
            {
            //there are more elements
                find->getNext()->setPrev(nullptr);
                this->setHead(find->getNext());
                delete find;
                return;
            }
        }
        
        
        while(currentNode != NULL)
        {
            if(currentNode == find)
            {
                
                if(currentNode->getNext() == NULL)
                {
                    //the searched element is the last one
                    find->getPrev()->setNext(nullptr);
                    this->setTail(find->getPrev());
                    delete find;
                    currentNode = NULL;
                }
                else
                {
                    //there are more elements after it
                    Node* q = currentNode->getNext();
                    q->setPrev(find->getPrev());
                    find->getPrev()->setNext(q);
                    delete find;
                    currentNode = q;
                }
            }
            else
                currentNode = currentNode->getNext();
        }
    }
    
    /*
     Gets the number of pairs from the list
     Returns an integer
     */
    int getSize()
    {
        int nr = 0;
        Node* currentNode = this->head;
        while(currentNode != NULL)
        {
            nr++;
            currentNode = currentNode->getNext();
        }
        return nr;
    }
    
    /*
     Gets the keys from the list
     Returns a sorted vector of strings
     */
    vector<string> getKeys()
    {
        vector<string> s;
        Node* currentNode = this->head;
        while(currentNode != NULL)
        {
            s.push_back(currentNode->getInfo().getKey());
            currentNode = currentNode->getNext();
        }
        return s;
    }
    
    /*
     Gets the values from the list
     Returns a vector of integers
     */
    vector<int> getValues()
    {
        vector<int> v;
        Node* currentNode = this->head;
        while(currentNode != NULL)
        {
            v.push_back(currentNode->getInfo().getValue());
            currentNode = currentNode->getNext();
        }
        return v;
    }
    
    /*
     Gets the Pairs from the list
     Returns a sorted vector of Pairs
     */
    vector<Pair> getPairs()
    {
        vector<Pair> p;
        Node* currentNode = this->head;
        while(currentNode != NULL)
        {
            p.push_back(currentNode->getInfo());
            currentNode = currentNode->getNext();
        }
        return p;
    }
    

    /*
     Destructor for a DLL
     */
    ~DLL()
    {
        Node* currentNode = this->head;
        while(currentNode != NULL)
        {
            Node* aux = new Node;
            this->setHead(aux);
            currentNode = currentNode->getNext();
            delete aux;
        }
    }
    
};

#endif /* DLLMap_hpp */
