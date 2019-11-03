/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：type_change.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	double a = 2.2;
	int b;
	int *p = NULL;
	//p = int*(0x123) error:指针强制转换只能使用如下：p=(int *)0x123
	b = (int)a + int(a);
	cout << b << endl;
	return 0;
}
