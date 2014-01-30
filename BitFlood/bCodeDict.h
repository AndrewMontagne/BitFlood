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

class bCodeDictionary : bCodeData
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
	bCodeData* at(string* key) { return this->at(key); }
    bCodeData* at(string key) { return values->at(key); }
	bCodeData* at(const char key) { return this->at(string(&key)); };
};

#endif
