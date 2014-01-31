//
//  bCodeDict.h
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#ifndef BitFlood_bCodeDict_h
#define BitFlood_bCodeDict_h

using namespace std;

class bCodeData;
enum bType;

#include "bCodeData.h"
#include <map>

class bCodeDictionary : public bCodeData
{
	friend class bCodeData;
private:
	bCodeDictionary(map<string, bCodeData*>* values_)
	{
		values = values_;
		containerType = bType::Dictionary;
	}
	map<string, bCodeData*>* values;
public:
    ~bCodeDictionary() { delete values; };
    bool contains(const char key[]) { return !(values->find(string(key)) == values->end()); }
	bCodeData* at(const char key[]) { return values->at(string(key)); };
};

#endif
