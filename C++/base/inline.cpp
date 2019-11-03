/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：inline.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

inline void func()
{
	int a = 100;
}

int main()
{
	for(int i=0; i< 10000; i++)
		func();
	return 0;
}
