/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：inherit.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Base{
	public:
		void func() {cout << "Base::func()\n";}
};

class Inherit:public Base{
public:
	void func() {cout << "Inherit::func()\n";}
};

int main()
{
	Base obj;
	Inherit obj1;

	obj.func();
	obj1.func();
	Base *p = &obj;
	p->func();
	p=&obj1;
	p->func();
	return 0;
}
