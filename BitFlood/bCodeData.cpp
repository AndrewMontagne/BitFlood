//
//  bCodeData.cpp
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#include "bCodeData.h"

#include "bCodeInt.h"
#include "bCodeList.h"
#include "bCodeDict.h"
#include "bCodeString.h"

bCodeData* bCodeData::parse(string *torrent, unsigned int startIndex, unsigned int* endIndex)
{
    unsigned int i = startIndex + 1;
	
    switch (torrent->at(i - 1))
    {
        case 'i':
        {
            int value = 0;
			bool isNegative = false;
            char current = 0;
            
            while((current = torrent->at(i)) != 'e')
            {
                if(current == '-')
                    isNegative = true;
                else
                {
                    value *= 10;
                    value -= '0' - current;
                }
                i++;
            }
			
			if(endIndex != NULL)
				*endIndex = i;
			
            return new bCodeInt(isNegative ? -value : value);
        }
        break;
            
        case 'l':
        {
			vector<bCodeData*>* values = new vector<bCodeData*>();
			
            while (torrent->at(i) != 'e')
            {
                unsigned int e = 0;
                values->push_back(parse(torrent, i, &e));
                i = e + 1;
            }
            
			if(endIndex != NULL)
				*endIndex = i;
			
            return new bCodeList(values);
        }
        break;
            
        case 'd':
        {
			map<string, bCodeData*>* values = new map<string, bCodeData*>();
			
			while (torrent->at(i) != 'e')
            {
                unsigned int e = 0;
                bCodeString* keyContainer = (bCodeString*)parse(torrent, i, &e);
				string key = keyContainer->getValue();
				delete keyContainer;
                i = e + 1;
				(*values)[key] = parse(torrent, i, &e);
				i = e + 1;
            }
			
			if(endIndex != NULL)
				*endIndex = i;
			
            return new bCodeDictionary(values);
        }
        break;
            
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            i--;
            unsigned int length = 0;
            char current = 0;
            
            while((current = torrent->at(i)) != ':')
            {
                length *= 10;
                length -= '0' - current;
                i++;
            }
            i++;
            
			if(endIndex != NULL)
				*endIndex = i + (length - 1);
			
            return new bCodeString(string(torrent->substr(i,length)));
        }
        break;
            
        default:
        {
            throw new exception();
        }
        break;
    }
}

bCodeData* bCodeData::forKey(const char key[])
{
	if(containerType == bType::Dictionary)
	{
		bCodeDictionary* alsoThis = (bCodeDictionary*)this;
		return alsoThis->at(key);
	}
	else
		return NULL;
}

bCodeData* bCodeData::atIndex(unsigned int index)
{
	if(containerType == bType::List)
	{
		bCodeList* alsoThis = (bCodeList*)this;
		return alsoThis->at(index);
	}
	else
		return NULL;
}
std::string bCodeData::toString()
{
	if(containerType == bType::String)
	{
		bCodeString* alsoThis = (bCodeString*)this;
		return alsoThis->getValue();
	}
	else
		return NULL;
}
int bCodeData::toInt()
{
	if(containerType == bType::Integral)
	{
		bCodeInt* alsoThis = (bCodeInt*)this;
		return alsoThis->getValue();
	}
	else
		return 0;
}