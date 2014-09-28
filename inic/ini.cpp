#include "ini.h"
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

INI::INI()
{
    key = new keys();
}

INI::~INI()
{
    ClearINI();
    delete(key);
}

int INI::ReadINI()
{
    string line;
    string type;
    int i;
    ifstream inf("matrix.ini");
    if (!inf.is_open()){
        return -1;
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
    return 0;
}

void INI::ClearINI()
{
    keys::iterator it;
    for(it=(*key).begin(); it!=(*key).end(); it++)
    {
        delete((*it).second);
        (*key).erase((*it).first);
    }
}

void INI::ShowINI()
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

keys* INI::GetINI()
{
    return key;
}

int INI::WriteINI(string path)
{
    string data;
    ofstream outf(path.c_str());
    if(!outf.is_open())
    {
        return -1;
    }
    keys::iterator it;
    for(it=(*key).begin(); it!=(*key).end(); it++)
    {
        data.append("[");
        data.append((*it).first);
        data.append("]");
        data.append("\n");
        cout << "[" << (*it).first << "]" << endl;
        values * val = (*it).second;
        values::iterator iv;
        for(iv=(*val).begin(); iv!=(*val).end(); iv++)
        {
            cout << (*iv).first << "=" << (*iv).second << endl;
        }
    }
    return 0;
}
