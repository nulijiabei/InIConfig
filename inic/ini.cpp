#include "ini.h"
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

INI::INI()
{
    key = new keys();
}

void INI::ReadINI()
{
    string line;
    string type;
    int i;
    ifstream inf("matrix.ini");
    if (!inf.is_open()){
        return;
    }
    while(getline(inf, line)){
        if (line.substr(0,1) ==  "#" || line.empty())
        {
            continue;
        }
        if (line.substr(0,1) ==  "[")
        {
            type = line.substr(1,line.length()-2);
            continue;
        }
        if(type.empty()) {
            continue;
        }
        i = line.find("=");
        if(i == -1)
        {
            continue;
        }
        if((*key)[type] == NULL)
        {
            values * val = new values();
            (*key)[type] = val;
        }
        values * val = (*key)[type];
        (*val)[line.substr(0,i)] = line.substr(line.find("=")+1,line.length());
    }
    inf.close();
}

void INI::WriteINI()
{
    keys::iterator it;
    for(it=(*key).begin(); it!=(*key).end(); it++)
    {
        cout << "[" << (*it).first << "]" << endl;
        values * val = (*it).second;
        values::iterator iv;
        for(iv=(*val).begin(); iv!=(*val).end(); iv++)
        {
            cout << (*iv).first << "=" << (*iv).second << endl;
        }
    }
}
