/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：struct.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

struct ADD{
#ifdef _T_
	int addr()
	{
		return (x+y);
	}
#else
	int add();
#endif
	int x;
	int y;

};

#ifndef _T_
int ADD::add()
{
	return (x+y);
}

#endif

int main()
{
	ADD obj = {1,2};
	ADD obj1 = {
		x:1,
		y:2,
	};

	cout << obj.x << endl;
	cout << obj1.y << endl;
	cout << obj1.add() << endl;
	cout << obj.add() << endl;
	return 0;
}
