/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：door_inherit.cpp
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
		virtual void open(){cout << "Door::open()\n";}
};

class Double_door:public Door{
	public:
		void open(){cout << "double door::open()\n";}
};

class Single_door:public Door{
	public:
		void open() {cout << "singleDoor::open()\n";}
};

void open(Door *p){
	p->open();
}

int main()
{
Door obj;
Single_door obj1;
Double_door obj2;

open(&obj);
open(&obj1);
open(&obj2);

return 0;
}
