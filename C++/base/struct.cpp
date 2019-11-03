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
	int x;
	int y;
};

int sum(int a,int b)
{
	return (a+b);
}

int main()
{
	ADD obj = {1,2};
	ADD obj1 = {
		x:1,
		y:2
	};

	cout << obj.x << endl;
	cout << obj1.y << endl;
	return 0;
}
