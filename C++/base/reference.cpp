/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：reference.cpp
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
	int a = 5;
	int &b = a;

	cout << "a = " << a << ",b = " << b << endl;

	int c= 10;
	b= c;
	cout << "a = " << a << ",b = " << b << endl;
	return 0;
}
