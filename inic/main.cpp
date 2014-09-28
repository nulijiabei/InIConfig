#include <iostream>
#include "ini.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    INI * ini = new INI();
    ini->ReadINI();
    ini->WriteINI();
    return 0;
}

