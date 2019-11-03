/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：ptr_bass.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

class A{
public:
	A(){cout << "A()\n";}
	virtual ~A(){cout << "~A()\n";};

	virtual void output(){cout <<"A output()\n";}
};

class B:public A{
	public:
		B(const char *info){
			cout << "B\n";
			m_buf = new char[256];
			strcpy(m_buf,info);
		};
		virtual ~B(){
			cout << "~B\n";
			delete[] m_buf;
		}
		virtual void output(){
			cout << m_buf;
		}

	private:
		char *m_buf;
};

int main()
{
	B b("opop\n");
	A a;
	A *pa1 = &a;
	pa1 = &b;
	pa1->output();
	B *pb = new B("flame\n");
	A *pa = pb;
	pa->output();
	return 0;
}
