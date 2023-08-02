#include <fstream>
#include <iostream>
#include <string>

#include "SmartPark.h"

using namespace std;

int hashFx( Profile& pres);

int main(int argc, char* argv[])
{
    string presidents = argv[1];
    string line;
    string presName;
    string presState;
    
    int lineLength;
    
    Profile* pres = NULL;

    SmartPark<Profile> theHashTable(hashFx);

    ifstream inStream;
    inStream.open(presidents, ios::in);

    while (inStream.peek() != EOF)
    {
        getline(inStream, line);

        lineLength = line.length();
        presName = line.substr(0, (lineLength - 3));
        presState = line.substr((lineLength - 2), lineLength);
        

        pres = new Profile(presName, presState);
        
        theHashTable.insert(*pres);
        //cout << "Adding: " << pres.name << " " << pres.state << endl;
    }

    cout << endl;
    theHashTable.print();
}

int hashFx(Profile& pres)
{
    string presName = pres.name;
    int presNameCount = presName.length();
    int insertToIndex = 0;

    for (int i = 0; i < presNameCount; i++)
    {
        insertToIndex = insertToIndex + presName[i];
    }

    insertToIndex = insertToIndex % 7;

    return insertToIndex;
}