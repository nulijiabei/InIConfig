#include "ini.h"
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

INI::INI(string _path)
{
    key = new keys();
    path = _path;
}

INI::~INI()
{
    ClearINI();
    delete(key);
}

int INI::ReadINI()
{
    ClearINI();
    string line;
    string type;
    int i;
    ifstream f(path.c_str());
    if (!f.is_open()){
        return -1;
    }
    while(getline(f, line)){
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
        if(key->find(type) == key->end())
        {
            values * val = new values();
            (*key)[type] = val;
        }
        values * val = (*key)[type];
        (*val)[line.substr(0,i)] = line.substr(line.find("=")+1,line.length());
    }
    f.close();
    return 0;
}

void INI::ClearINI()
{
    keys::iterator it;
    for(it=(*key).begin(); it!=(*key).end(); it++)
    {
        (*(*it).second).clear();
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
        values * vals = (*it).second;
        values::iterator iv;
        for(iv=(*vals).begin(); iv!=(*vals).end(); iv++)
        {
            cout << (*iv).first << "=" << (*iv).second << endl;
        }
    }
}

string INI::GetValByKeysAndVals(string _keys, string _values)
{
    if (key->find(_keys) == key->end())
    {
        return "";
    }
    values * vals = (*key)[_keys];
    if (vals->find(_values) == vals->end())
    {
        return "";
    }
    return (*vals)[_values];
}

int INI::DelValByKeysAndVals(string _keys, string _values)
{
    if (key->find(_keys) == key->end())
    {
        return -1;
    }
    values * vals = (*key)[_keys];
    if (vals->find(_values) == vals->end())
    {
        return -1;
    }
    (*vals).erase(_values);
    if ((*vals).size() == 0)
    {
        delete(vals);
        (*key).erase(_keys);
    }
    return 0;
}

void INI::AppendValByKeysAndVals(string _keys, string _values, string _value)
{
    if(key->find(_keys) == key->end())
    {
        values * val = new values();
        (*key)[_keys] = val;
    }
    values * val = (*key)[_keys];
    (*val)[_values] = _value;
}

int INI::WriteINI()
{
    string data;
    ofstream f(path.c_str());
    if(!f.is_open())
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
        values * val = (*it).second;
        values::iterator iv;
        for(iv=(*val).begin(); iv!=(*val).end(); iv++)
        {
            data.append((*iv).first);
            data.append("=");
            data.append((*iv).second);
            data.append("\n");
        }
    }
    f.write(data.c_str(), strlen(data.c_str()));
    f.flush();
    f.close();
    return 0;
}
