/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：weak_ptr.cpp
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
		~Demo(){cout << "~Demo()\n";}

		void func(){cout << "func()\n";}
};

int main()
{
	shared_ptr<Demo> p(new Demo);
	cout << "line:" << __LINE__ << "," << p.use_count() << endl;
	weak_ptr<Demo> pp=p;
	cout << "line:" << __LINE__ << "," << p.use_count() << endl;
	shared_ptr <Demo> p1 = p;
	cout << "line:" << __LINE__ << "," << p.use_count() << endl;

	{
		shared_ptr<Demo> p2(p);
		cout << "line:" << __LINE__ << "," << p.use_count() << endl;

	}
	cout << "line:" << __LINE__ << "," << p.use_count() << endl;
	p->func();
	//pp->func();弱指针不能指向成员，转换为shared_ptr后可以
	shared_ptr<Demo> p3 = pp.lock();
	p3->func();
	cout << "line:" << __LINE__ << "," << p.use_count() << endl;

	p1.reset();
	cout << "line:" << __LINE__ << "," << p.use_count() << endl;

	p3.reset();
	if(pp.expired())
		cout << "Denmo is not exist\n";
	else
		cout << "Denmo is exist\n";

	return 0;
}

