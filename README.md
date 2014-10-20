------------
C++ .INI 格式文件读写

	#include "INIConfig.h"
	#include <iostream>
	#include <vector>

	int main()
	{

	    // INI
	    INIConfig * ini = new INIConfig("matrix.ini");

	    // 读取
	    ini->ReadINI();

	    // 清空
	    ini->Clear();

	    // 插入
	    ini->Append("default", "hello", "world");

	    // 查看
	    ini->ShowINI();

	    // 写入
	    ini->WriteINI(); // False Error

	    // 取值
	    ini->GetObject("default", "hello", "false");
	    ini->GetObject("default", "world", "false");

	    // 取列
	    vector<string> project = ini->GetProject("default");

	    // 返回
	    return 0;

	}

