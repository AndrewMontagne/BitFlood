//
//  bCodeList.h
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#ifndef BitFlood_bCodeList_h
#define BitFlood_bCodeList_h

#include "bCodeData.h"

class bCodeList : public bCodeData
{
	friend class bCodeData;
private:
	bCodeList(vector<bCodeData*>* values_)
	{
		values = values_;
		containerType = bType::List;
	}
	vector<bCodeData*>* values;
public:
    ~bCodeList() { delete values; }
    unsigned int length() { return (unsigned int)values->size(); };
    bCodeData* at(unsigned int index) { return values->at(index); }
};

#endif
