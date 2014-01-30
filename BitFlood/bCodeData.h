//
//  bCodeData.h
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#ifndef __BitFlood__bCodeData__
#define __BitFlood__bCodeData__

#include <iostream>
#include <map>
#include <list>

using namespace std;

enum bType
{
    d = 0,
    i = 1,
    s = 2,
    l = 3
};

class bCodeData
{
    
    private:
        bType containerType;
    protected:
        bCodeData();
        ~bCodeData();
    public:
        static bCodeData* parse(string* torrent, unsigned int startIndex, unsigned int* endIndex);
        
};

class bCodeDictionary : bCodeData
{
private:
public:
    bCodeData* operator[](std::string key) { return NULL; }
};

class bCodeList : bCodeData
{
    bCodeData* operator[](unsigned int index) { return NULL; }
};

class bCodeString : bCodeData
{
    std::string getValue();
};

class bCodeInt : bCodeData
{
    int getValue()
};

#endif /* defined(__BitFlood__bCodeData__) */
