/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：reference1.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

void swap(int &a,int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

int main()
{
	int a = 10;
	int b = 20;
	swap(a,b);
	cout << "a = " << a << "b = " << b << endl;
	return 0;
}
