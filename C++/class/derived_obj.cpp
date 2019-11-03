/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：derived_obj.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>

class Base{
	public:
		virtual void fun()
		{
			cout << "Base fun() is Called\n";
		}
};

class Derived:public Base{
	public:
		void fun(){cout <<"Derived fun() is Called\n";}
};

void fun1(Base b){b.fun();}

void fun2(Base *b){b->fun();}

void fun3(Base &b){b.fun();}

int main()
{
	Derived d;
	fun1(d);
	fun2(&d);
	fun3(d);

	system("pause");
	return 0;
}
