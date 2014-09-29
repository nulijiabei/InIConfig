------------
C++ .INI 格式文件读写

	#include "ini.h"

	int main()
	{

	    // INI
	    INI * ini = new INI("ini");

	    // 读取
	    ini->ReadINI(); // -1 Error

	    // 写入 -1 Error
	    ini->WriteINI(); // -1 Error

	    // 查看
	    ini->ShowINI();

	    // 获取
	    ini->GetINI();

	    // 清空
	    ini->ClearINI();

	    // 取值
	    ini->GetValByKeys("keys","values")

            // 空
	    ini->GetValByKeys("keys","values").empty() // Error

            // 取值
            ini->GetValsByKeys("keys") // NULL Error

	    // 释放
	    delete(ini);

	    return 0;

	}
