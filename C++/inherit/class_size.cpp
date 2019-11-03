/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_size.cpp
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
	Base(){val = 1;}
	virtual void func() {cout << "Base::func()\n";}
	virtual void func1() {cout << "Base::func1()\n";};
private:
	int val;
};

class Inherit:public Base{
	public:
		Inherit(){var = 100;}
		void func3(){cout << "Inherit::func()\n"; }
		virtual void func2() {cout << "Inherit::func2()\n";}

	private:
		int var;
};

typedef void (*FUNC)();
int main()
{
	Inherit obj;
	cout << sizeof(obj) << endl;//虚函数首地址占4个字节，val var各占4字节

	cout << *((int *)&obj+1) << endl;
	cout << *((int *)&obj+2) << endl;

	int addr = *(int *)&obj;//虚函数表地址指针，指向第一个虚函数，addr应该为函数指针地址
	(*(FUNC *)addr)();
	(*((FUNC *)addr+1))();
	(*((FUNC *)addr+2))();
	return 0;
}
