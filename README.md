------------
C++ .INI 格式文件读写

	#include <iostream>
	#include "ini.h"

	using namespace std;

	int main()
	{

	    // INI
	    INI * ini = new INI("ini");
	    // 读取 -1 Error
	    ini->ReadINI();
	    // 写入 -1 Error
	    ini->WriteINI();
	    // 查看
	    ini->ShowINI();
	    // 获取
	    ini->GetINI();
	    // 清空
	    ini->ClearINI();

	    return 0;
	}
