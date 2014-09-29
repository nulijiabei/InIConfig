------------
C++ .INI 格式文件读写

	#include "ini.h"

	int main()
	{

	    // INI
	    INI * ini = new INI("ini");

	    // 读取
	    ini->ReadINI(); // -1 Error

	    // 写入
	    ini->WriteINI(); // -1 Error

	    // 取值
	    ini->GetValByKeysAndVals("keys", "values");

	    // 空
	    ini->GetValByKeysAndVals("keys", "values").empty(); // Error

	    // 添加
	    ini->AppendValByKeysAndVals("keys", "values", "value");

	    // 删除
	    ini->DelValByKeysAndVals("keys", "values"); // -1 Error

	    // 查看
	    ini->ShowINI();

	    // 清空
	    ini->ClearINI();

	    // 释放
	    delete(ini);

	    // 返回
	    return 0;

	}

