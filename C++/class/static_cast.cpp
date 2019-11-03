/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：static_cast.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Bird{
	public:
		virtual void fly(){
		cout << "i am fly\n";
		}
};

class Penguin:public Bird{
	public:
		virtual void fly(){
		cout << "i am not fly\n";
		}
};


int main()
{
	Penguin* p = new Penguin;
	Bird* b = static_cast<Bird *>(p);/*派生类转换为基类，安全可行*/
	b->fly();
#if 0
	Bird* q = new Bird;
	Penguin* s = static_cast<Penguin *>(q);/*基类转换为派生类，不安全需要谨慎*/
	if(p != nullptr){
		p->fly();
	}
#else
	Bird* q = new Bird;
	Penguin* s = dynamic_cast<Penguin *>(q);/*基类转换为派生类，不安全需要谨慎*/
	if(p != nullptr){
		p->fly();
	}
#endif
	return 0;
}
