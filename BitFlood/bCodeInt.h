//
//  bCodeInt.h
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#ifndef BitFlood_bCodeInt_h
#define BitFlood_bCodeInt_h

class bCodeInt : public bCodeData
{
	friend class bCodeData;
private:
	bCodeInt(int value_)
	{
		value = value_;
		containerType = bType::Integral;
	}
	int value;
public:
    int getValue() { return value; };
};

#endif
