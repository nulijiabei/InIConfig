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

bool INI::ReadINI()
{
    ClearINI();
    string line;
    string type;
    int i;
    ifstream f(path.c_str());
    if (!f.is_open()){
        return false;
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
        values * vals = (*key)[type];
        (*vals)[line.substr(0,i)] = line.substr(line.find("=")+1,line.length());
    }
    f.close();
    return true;
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

string INI::GetValByKeysAndVals(string _keys, string _values, string _default)
{
    if (key->find(_keys) == key->end())
    {
        return _default;
    }
    values * vals = (*key)[_keys];
    if (vals->find(_values) == vals->end())
    {
        return _default;
    }
    return (*vals)[_values];
}

bool INI::DelValByKeysAndVals(string _keys, string _values)
{
    if (key->find(_keys) == key->end())
    {
        return false;
    }
    values * vals = (*key)[_keys];
    if (vals->find(_values) == vals->end())
    {
        return false;
    }
    (*vals).erase(_values);
    if ((*vals).size() == 0)
    {
        delete(vals);
        (*key).erase(_keys);
    }
    return true;
}

void INI::AppendValByKeysAndVals(string _keys, string _values, string _value)
{
    if(key->find(_keys) == key->end())
    {
        values * vals = new values();
        (*key)[_keys] = vals;
    }
    values * vals = (*key)[_keys];
    (*vals)[_values] = _value;
}

bool INI::WriteINI()
{
    string data;
    ofstream f(path.c_str());
    if(!f.is_open())
    {
        return false;
    }
    keys::iterator it;
    for(it=(*key).begin(); it!=(*key).end(); it++)
    {
        data.append("[");
        data.append((*it).first);
        data.append("]");
        data.append("\n");
        values * vals = (*it).second;
        values::iterator iv;
        for(iv=(*vals).begin(); iv!=(*vals).end(); iv++)
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
    return true;
}
