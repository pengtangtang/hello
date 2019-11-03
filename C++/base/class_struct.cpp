/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_struct.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
/*
struct STU{
	string name;
	int age;
};
*/
class STU{
	public:
		string name;
		int age;
};

int main()
{
	STU stu;
	stu.age = 10;
	cout << "stu.age:" << stu.age << endl;
	return 0;
}
