/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：unique_ptr.cpp
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
	unique_ptr<Demo> p(new Demo);
	p->func();
	unique_ptr<Demo> pp(new Demo) ;
	return 0;
}
