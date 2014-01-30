//
//  main.cpp
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

#include <iostream>

using namespace std;

#include <map>

struct bNode
{
    enum bNodeType
    {
        bNodeTypeDict = 1,
        bNodeTypeArray = 2,
        bNodeTypeString = 3,
        bNodeTypeInt = 4
    };
    
    bNodeType type;
    void* value;
    
    public:
    
    bNode(bNodeType type_, void* value_)
    {
        type = type_;
        value = value_;
    }
    ~bNode()
    {
        if(value != NULL)
        {
            switch(type)
            {
                case bNodeTypeArray:
                    delete [] (bNode*)value;
                    break;
                case bNodeTypeDict:
                    delete (map<string, bNode>*)value;
                    break;
                case bNodeTypeString:
                    delete (string*)value;
                    break;
                case bNodeTypeInt:
                    delete (int*)value;
                    break;
            }
        }
    }
};

bNode* processTorrent(string torrent, int startIndex, int* endIndex)
{
    int i = startIndex + 1;
    
    switch (torrent[i - 1])
    {
        case 'i':
        {
            int value = 0;
            
            while(torrent[i] != 'e')
            {
                value *= 10;
                value -= 0x30 - (int)torrent[i];
                i++;
            }
            
            *endIndex = i;
            return NULL;
        }
        break;
            
        case 'l':
        {
            while (torrent[i] != 'e')
            {
                int e = 0;
                processTorrent(torrent, i, &e);
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
            
        default:
        {
            i--;
            int length = 0;
            
            while(torrent[i] != ':')
            {
                length *= 10;
                length -= 0x30 - (int)torrent[i];
                i++;
            }
            
            i++;
            string data = torrent.substr(i,length);
            
            *endIndex = i + (length - 1);
            return NULL;
        }
        break;
    }
}

int main(int argc, const char * argv[])
{
    FILE *torFile = fopen("text.txt.torrent", "r");
    
    if(torFile == NULL)
    {
        perror ("The following error occurred");
        return 1;
    }
    
    string torrent = string();
    
    char * buffer = new char[255];
    
    size_t size;
    
    while ((size = fread(buffer, 1, 255, torFile)) > 0)
    {
        string part(buffer, size);
        torrent += part;
    }
    
    delete buffer;
    fclose(torFile);
    
    int end = 0;
    bNode* root = processTorrent(string("l55:http://s3-tracker.eu-west-1.amazonaws.com:6969/announce55:http://s3-tracker.eu-west-1.amazonaws.com:6969/announcee"),0,&end);
}
