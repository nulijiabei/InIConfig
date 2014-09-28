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
    INI();
    ~INI();
public:
    int ReadINI();
    int WriteINI(string);
    void ClearINI();
    void ShowINI();
    keys* GetINI();
private:
    keys * key;
};

#endif // INI_H
