//
//  bCodeString.h
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#ifndef BitFlood_bCodeString_h
#define BitFlood_bCodeString_h

class bCodeString : public bCodeData
{
	friend class bCodeData;
private:
	bCodeString(string value_)
	{
		value = value_;
		containerType = bType::String;
	}
	string value;
public:
    string getValue() { return value; }
};

#endif
