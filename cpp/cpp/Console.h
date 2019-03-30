//
//  Console.h
//  cpp
//
//  Created by Crisan Alexandra on 05/06/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Console_h
#define Console_h

#include "DLLMap.hpp"
#include "Iterator.hpp"

class Console
{
private:
    DLL Portfolio;

public:
    
    /*
     Default constructor for a Console
     */
    Console() {}
    
    /*
     Function that prints the menu of the console
     */
    void printMenu()
    {
        cout<<"1. Add an (artist, number of pieces) pair to the portfolio\n";
        cout<<"2. See the whole portfolio\n";
        cout<<"3. Delete an artist with a given name\n";
        cout<<"4. Search for an artist with a given name\n";
        cout<<"5. View the list from the start\n";
        cout<<"6. View the list from the end\n";
        cout<<"7. Next artist\n";
        cout<<"8. Previous artist\n";
        cout<<"0. Exit\n";
    }
    
    /*
     Function that prints the list using an iterator
     input: it (Iterator)
     output: none
     */
    void printList(Iterator &it)
    {
        it.setFirst();
        while(it.valid())
        {
            Node * aux = it.getCurrent();
            aux->toString();
            it.next();
        }
    }
    
    /*
     Function that initializes the list
     */
    void initList()
    {
        this->Portfolio.add("Robin", 20);
        this->Portfolio.add("Ted", 3);
        this->Portfolio.add("Barney", 10);
        this->Portfolio.add("Rachel", 15);
        this->Portfolio.add("Monica", 18);
        this->Portfolio.add("Ross", 19);
        this->Portfolio.add("Joey", 30);
        this->Portfolio.add("Chandler", 23);
        this->Portfolio.add("Lily", 5);
        this->Portfolio.add("Marshall", 12);
        
    }
    
    /*
     Starts viewing the Portfolio from the beginning
     input: it (Iterator)
     output: none
     */
    void first(Iterator &it)
    {
        it.setFirst();
        it.getCurrent()->toString();
    }
    
    /*
     Starts viewing the Portfolio from the end
     input: it (Iterator)
     output: none
     */
    void last(Iterator &it)
    {
        it.setLast();
        it.getCurrent()->toString();
    }
    
    /*
     Moves the iterator to the next element in the list
     input: it (Iterator)
     output: none (throws an exception if it reached the end of the list)
     */
    void next(Iterator &it)
    {
        it.next();
        if(it.valid())
            it.getCurrent()->toString();
        else
            throw Exception("Can't go any further!");
    }
    
    /*
     Moves the iterator to the previous element in the list
     input: it (Iterator)
     output: none (throws an exception if it reached the start of the list)
     */
    void prev(Iterator &it)
    {
        it.previous();
        if(it.valid())
            it.getCurrent()->toString();
        else
            throw Exception("Can't go any further!");
    }
    
    /*
     Function that starts the application
     */
    void start()
    {
        int option;
        this->printMenu();
        this->initList();
        Iterator it{this->Portfolio};
        while(true)
        {
            cout<<"Enter an option: ";
            cin>>option;
            
            if(option == 0)
                break;
            else if(option == 1)
            {
                cout<<"You chose to add an artist and the number of his pieces\n";
                
                cout<<"Name of the artist: ";
                string name;
                getline(cin, name);
                getline(cin, name);
                
                cout<<"Number of pieces: ";
                int nr;
                cin>>nr;
                
                try
                {
                    this->Portfolio.add(name, nr);
                }
                catch(Exception &e)
                {
                    cout<<e.what()<<endl;
                }
                
            }
            else if(option == 2)
            {
                this->printList(it);
                cout<<this->Portfolio.getSize()<<" pairs\n";
                vector<string> s = this->Portfolio.getKeys();
                for(auto a: s)
                    cout<<a<<" ";
                cout<<endl;
                vector<int> v = this->Portfolio.getValues();
                for(auto a: v)
                    cout<<a<<" ";
                cout<<endl;
                vector<Pair> p = this->Portfolio.getPairs();
                for(auto a: p)
                    cout<<"("<<a.getKey()<<", "<<a.getValue()<<") ";
                cout<<endl;
            }
            else if(option == 3)
            {
                cout<<"You chose to delete an artist. Name? ";
                string name;
                getline(cin, name);
                getline(cin, name);
                
                this->Portfolio.del(name);
            }
            else if(option == 4)
            {
                cout<<"You chose to search an artist. Name? ";
                string name;
                getline(cin, name);
                getline(cin, name);
                
                Node* n = this->Portfolio.search(name);
                if (n != NULL)
                    n->toString();
                else cout<<"Not found\n'";
            }
            else if(option == 5)
            {
                cout<<"From the start: "<<endl;
                this->first(it);
            }
            else if(option == 6)
            {
                cout<<"From the end: "<<endl;
                this->last(it);
            }
            else if(option == 7)
            {
                cout<<"Next artist: ";
                try
                {
                    this->next(it);
                }
                catch(Exception &e)
                {
                    cout<<e.what()<<endl;
                }
            }
            else if (option == 8)
            {
                cout<<"Previous artist: ";
                try
                {
                    this->prev(it);
                }
                catch(Exception &e)
                {
                    cout<<e.what()<<endl;
                }
            }
        }
        
    }
    
    /*
     Default destructor for a Console
     */
    ~Console() {}
    
};


#endif /* Console_h */
