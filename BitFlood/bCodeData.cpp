//
//  bCodeData.cpp
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#include "bCodeData.h"

bCodeData* bCodeData::parse(string *torrent, unsigned int startIndex, unsigned int* endIndex)
{
    unsigned int i = startIndex + 1;
    
    switch (torrent->at(i - 1))
    {
        case 'i':
        {
            int value = 0;
            
            while(torrent->at(i) != 'e')
            {
                value *= 10;
                value -= 0x30 - (int)torrent->at(i);
                i++;
            }
            
            *endIndex = i;
            return NULL;
        }
        break;
            
        case 'l':
        {
            while (torrent->at(i) != 'e')
            {
                unsigned int e = 0;
                parse(torrent, i, &e);
                i = e + 1;
            }
            *endIndex = i;
            return NULL;
        }
        break;
            
        case 'd':
        {
            *endIndex = i;
            return NULL;
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
            
            while(torrent->at(i) != ':')
            {
                length *= 10;
                length -= 0x30 - (int)torrent->at(i);
                i++;
            }
            
            i++;
            string data = torrent->substr(i,length);
            
            *endIndex = i + (length - 1);
            return NULL;
        }
        break;
            
        default:
        {
            throw new exception();
        }
        break;
    }
}