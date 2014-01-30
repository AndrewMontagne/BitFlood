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
#include <vector>

class bCodeDictionary;
class bCodeInteger;
class bCodeList;
class bCodeString;

using namespace std;

enum bType
{
    Dictionary = 0,
    Integral = 1,
    String = 2,
    List = 3
};

class bCodeData
{
private:
        
protected:
	bCodeData() {}
	~bCodeData() {}
		bType containerType;
public:
	bCodeData* forKey(const char key[]);
	bCodeData* atIndex(unsigned int index);
	std::string toString();
	int toInt();
	
	static bCodeData* parse(string* torrent, unsigned int startIndex, unsigned int* endIndex);
};

#endif /* defined(__BitFlood__bCodeData__) */
