//
//  Tests.h
//  cpp
//
//  Created by Crisan Alexandra on 05/06/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Tests_h
#define Tests_h

#include "DLLMap.hpp"
#include <assert.h>
#include <vector>
#include <string>

class Tests
{
public:
    
    /*
     Default constructor for Tests
     */
    Tests(){}
    
    /*
     Calls all the test functions
     */
    void testAll()
    {
        this->testSearch();
        this->testDelete();
        this->testAdd();
        this->testgetSize();
        this->testgetKeys();
        this->testgetValues();
        this->testgetPairs();
        this->testgetters();
    }
    
    /*
     Initializes the list for the tests
     Returns a DLL
     */
    DLL initList()
    {
        DLL l;
        l.add("Anne", 20);
        l.add("David", 1);
        l.add("Brianna", 10);
        return l;
    }
    
    /*
     Tests the search function from the DLL
     */
    void testSearch()
    {
        DLL l = this->initList();
        Node *n = l.search("David");
        assert(n->getInfo().getKey() == "David");
        assert(n->getInfo().getValue() == 1);
        
        Node *m = l.search("Lily");
        assert(m == NULL);
    }
    
    /*
     Tests the delete function from the DLL
     */
    void testDelete()
    {
        DLL l = this->initList();
        //delete the last element
        l.del("Brianna");
        assert(l.getSize() == 2);
        //delete the first element
        l.del("Anne");
        assert(l.getSize() == 1);
        
        DLL s{};
        //delete the only element
        s.add("Ana", 2);
        s.del("Ana");
        assert(s.getSize() == 0);
        
        DLL c = this->initList();
        //delete an element from the middle
        c.del("David");
        assert(c.getSize() == 2);
        
        //try to delete something that doesn't exist
        try
        {
            c.del("Serena");
        }
        catch (Exception& e)
        {
            
        }
    }
    
    /*
     Tests the add function from the DLL
     */
    void testAdd()
    {
        DLL l{};
        //empty list
        l.add("Maria", 21);
        assert(l.getSize() == 1);
        
        DLL s{};
        s.add("Dave", 22);
        //add something before
        s.add("Andreea", 10);
        assert(s.getSize() == 2);
        assert(s.getHead()->getInfo().getKey() == "Andreea");
        
        DLL a{};
        a.add("Alina", 3);
        //add something after
        a.add("Matt", 8);
        assert(a.getSize() == 2);
        assert(a.getTail()->getInfo().getKey() == "Matt");
        
        DLL b = this->initList();
        //add something in the middle
        b.add("Chris", 24);
        assert(b.getSize() == 4);
        assert(b.getKeys().at(2) == "Chris");
    }
    
    /*
     Tests the getSize function from the DLL
     */
    void testgetSize()
    {
        DLL l = this->initList();
        assert(l.getSize() == 3);
    }
    
    /*
     Tests the getKeys function from the DLL
     */
    void testgetKeys()
    {
        DLL l = this->initList();
        vector<string> s = l.getKeys();
        
        assert(s.at(0) == "Anne");
        
    }
    
    /*
     Tests the getValues function from the DLL
     */
    void testgetValues()
    {
        DLL l = this->initList();
        vector<int> v = l.getValues();
        
        assert(v.at(0) == 20);
        
    }
    
    /*
     Tests the getPairs function from the DLL
     */
    void testgetPairs()
    {
        DLL l = this->initList();
        vector<Pair> p = l.getPairs();
        
        assert(p.at(0).getKey() == "Anne");
        assert(p.at(0).getValue() == 20);
        
    }
    
    /*
     Tests the getHead and getTail functions from the DLL
     */
    void testgetters()
    {
        DLL l = this->initList();
        assert(l.getHead()->getInfo().getKey() == "Anne");
        assert(l.getTail()->getInfo().getKey() == "David");
    }
    
    /*
     Default destructor for Tests
     */
    ~Tests(){}
    
};


#endif /* Tests_h */
