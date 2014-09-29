#ifndef INI_H
#define INI_H

#include <map>
#include <string>

using namespace std;

typedef map<string, string> values;
typedef map<string, values*> keys;

class INI
{
public:
    INI(string);
    ~INI();
public:
    int ReadINI();
    int WriteINI();
    void ClearINI();
    void ShowINI();
    void AppendValByKeysAndVals(string, string, string);
    int DelValByKeysAndVals(string, string);
    string GetValByKeysAndVals(string, string);
private:
    keys * key;
    string path;
};

#endif // INI_H
