/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：new.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

int main()
{
#if 0
	int *p = new int;
	*p = 100;
#else
	int *p = new int(10);//赋初值为10
#endif
	cout << "*p= " << *p << endl;

	char *q = new char[100];
	strcpy(q,"hello");
	cout << "str:" << q << endl;
	delete [] q;
	delete p;/*记得要一一匹配*/
	return 0;
}
