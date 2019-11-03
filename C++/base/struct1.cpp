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

	int (*add)(const ADD&);
};

int sum(const ADD& obj)
{
	return (obj.x+obj.y);
}

int main()
{
	ADD obj = {1,2,sum};
	ADD obj1 = {
		x:1,
		y:2,
		add:sum
	};

	cout << obj.x << endl;
	cout << obj1.y << endl;
	cout << obj1.add(obj) << endl;
	return 0;
}
