------------
C++ .INI 格式文件读写

	#include "ini.h"

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
	    // 释放
	    delete(ini);

	    return 0;
	}
