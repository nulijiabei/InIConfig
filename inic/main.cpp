#include <iostream>
#include "ini.h"

using namespace std;

int main()
{

    // INI
    INI * ini = new INI();
    // 读取 -1 Error
    ini->ReadINI("ini");
    // 写入 -1 Error
    ini->WriteINI("ini");
    // 查看
    ini->ShowINI();
    // 获取
    ini->GetINI();
    // 清空
    ini->ClearINI();

    return 0;
}

