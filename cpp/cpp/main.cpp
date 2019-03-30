//
//  main.cpp
//  cpp
//
//  Created by Crisan Alexandra on 13/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include <iostream>
#include "Console.h"
#include "Tests.h"

int main()
{
    Tests t{};
    t.testAll();
    Console c{};
    c.start();
    return 0;
}
