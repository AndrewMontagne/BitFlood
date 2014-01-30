//
//  main.cpp
//  BitFlood
//
//  Created by Joshua O'Rourke on 30/01/2014.
//  Copyright (c) 2014 Joshua O'Rourke. All rights reserved.
//

using namespace std;

#include <iostream>
#include <map>
#include "bCodeData.h"
#include "bCodeString.h"
#include "bCodeDict.h"
#include "bCodeInt.h"
#include "bCodeList.h"

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
    
    bCodeData *parsedTorrent = bCodeData::parse(&torrent, 0, NULL);
	
	string announce = parsedTorrent->forKey("announce")->toString();
	string filename = parsedTorrent->forKey("info")->forKey("name")->toString();
	int length = parsedTorrent->forKey("info")->forKey("length")->toInt();
	cout <<  "Torrent links to file '" << filename << "' which is " << length << " bytes in size" << endl;
}
