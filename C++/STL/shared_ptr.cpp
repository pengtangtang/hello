/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：shared_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <memory>

class Demo{
	public:
		Demo(){cout << "Demo()\n";}
		Demo(const Demo &obj){cout << "Demo(const Demo &)\n";}
		virtual ~Demo(){cout << "~Demo()\n";}

		void func(){cout << "func()\n";}
};

void test()
{
#if 0 
	shared_ptr<Demo> p(new Demo);
	p->func();
	cout << "shared_ptr end\n";
//	Demo *p = new Demo;
#else
	shared_ptr<Demo> q = make_shared<Demo> (Demo());
	q->func();
	cout << "shared_ptr end\n";
#endif
}

int main()
{
	test();
	test();
	test();
	return 0;
}
