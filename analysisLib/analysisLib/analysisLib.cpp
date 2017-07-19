/*
 *  analysisLib.cpp
 *  analysisLib
 *
 *  Created by Alistair Baxter on 19/07/2017.
 *  Copyright © 2017 Alistair Baxter. All rights reserved.
 *
 */

#include <iostream>
#include "analysisLib.hpp"
#include "analysisLibPriv.hpp"

void analysisLib::HelloWorld(const char * s)
{
    analysisLibPriv *theObj = new analysisLibPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void analysisLibPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

