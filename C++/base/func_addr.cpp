/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：func_addr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
typedef int(*entry_t)(int argc,char *argv[]);

int main(int argc,char *argv[])
{
	entry_t addr = main;
	cout << "main = " << main;
	cout << "addr = " << addr;
	return 0;
}
