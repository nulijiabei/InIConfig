#ifndef INICONFIG_H
#define INICONFIG_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class INIConfig
{
public:
    INIConfig(string);
    ~INIConfig();
private:
    typedef map<string, string> object;
public:
    bool ReadINI();
    bool WriteINI();
    void ShowINI();
    void Clear();
    void Append(string , string, string);
    string GetObject(string, string, string);
    vector<string> GetProject(string);
private:
    map<string, object>*  project;
    string path;
};

#endif // INICONFIG_H
