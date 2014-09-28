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
public:
    void ReadINI();
    void WriteINI();
private:
    keys * key;
};

#endif // INI_H
