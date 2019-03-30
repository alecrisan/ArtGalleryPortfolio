//
//  Exception.h
//  cpp
//
//  Created by Crisan Alexandra on 05/06/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Exception_h
#define Exception_h

#include <string>
#include <exception>

using namespace std;
class Exception: public exception
{
private:
    string message;
    
public:
    /*
     Constructor for an Exception
     */
    Exception(const string &mess): message(mess) {}
    
    virtual const char* what()
    {
        return message.c_str();
    }
    
    
};

#endif /* Exception_h */
