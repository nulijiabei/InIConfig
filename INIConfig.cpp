#include "INIConfig.h"
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#include <vector>

INIConfig::INIConfig(string _path)
{
    project = new map<string, object>();
    path = _path;
}

INIConfig::~INIConfig()
{
    delete(project);
}

bool INIConfig::ReadINI()
{
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
        if(project->find(type) == project->end())
        {
            object obj;
            (*project)[type] = std::move(obj);
        }
        object obj = (*project)[type];
        obj[line.substr(0,i)] = line.substr(line.find("=")+1,line.length());
        (*project)[type] = std::move(obj);
    }
    f.close();
    return true;
}

void INIConfig::ShowINI()
{
    map<string, object>::iterator it;
    for(it = project->begin(); it != project->end(); it++)
    {
        cout << "[" << (*it).first << "]" << endl;
        object obj = (*it).second;
        map<string, string>::iterator iv;
        for(iv=obj.begin(); iv!=obj.end(); iv++)
        {
            cout << (*iv).first << "=" << (*iv).second << endl;
        }
    }
}

void INIConfig::Clear()
{
    map<string,object>::iterator it;
    for(it = project->begin(); it != project->end(); it++)
    {
        project->erase((*it).first);
    }
}

string INIConfig::GetObject(string _project, string _object, string _default)
{
    if (project->find(_project) == project->end())
    {
        return _default;
    }
    object obj = (*project)[_project];
    if (obj.find(_object) == obj.end())
    {
        return _default;
    }
    return obj[_object];
}

vector<string> INIConfig::GetProject(string _project)
{
    vector<string> list;
    map<string, object>::iterator it;
    for(it = project->begin(); it != project->end(); it++)
    {
        if((*it).first == _project)
        {
            object obj = (*it).second;
            map<string, string>::iterator iv;
            for(iv = obj.begin(); iv != obj.end(); iv++)
            {
                list.push_back((*iv).first);
            }
        }
    }
    return std::move(list);
}

void INIConfig::Append(string _project, string _object, string _value)
{
    if(project->find(_project) == project->end())
    {
        object obj;
        (*project)[_project] = std::move(obj);
    }
    object obj = (*project)[_project];
    obj[_object] = _value;
    (*project)[_project] = std::move(obj);
}

bool INIConfig::WriteINI()
{
    string data;
    ofstream f(path.c_str());
    if(!f.is_open())
    {
        return false;
    }
    map<string, object>::iterator it;
    for(it = project->begin(); it!=project->end(); it++)
    {
        data.append("[");
        data.append((*it).first);
        data.append("]");
        data.append("\n");
        object obj = (*it).second;
        map<string, string>::iterator iv;
        for(iv=obj.begin(); iv!=obj.end(); iv++)
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
