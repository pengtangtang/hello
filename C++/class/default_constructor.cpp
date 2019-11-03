/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：default_constructor.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class A{
	public:
		A(){cout << "A\n";}
};
class B{
	public:
		explicit B(int x = 0,bool b = true)
		{cout << "B\n";}
};

class C{
	public:
		explicit C(int x){cout << "C\n";}
};

void do_something(B bObj1)
{
	cout << "do_something\n";
}

int main()
{	A a;
	B b;
	C c(2);
	do_something(b);

	return 0;
}
