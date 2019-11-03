/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：abstruct.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Door{
	public:
		virtual void open() = 0;
};

class Single_door:public Door{
	public:
		void open() {cout << "Single_door::open()\n";}
};

int main()
{
//	Door obj1;
	Single_door obj;
	return 0;
}
