/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：overload1.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int add(int a){/*整型变量或常量*/
	return (a+a);
}

int add(int &a){/*整型变量*/
	return (a+a);
}

class print_data{
	public:
		void print(int i){
		cout << "print(int):" << i << endl;
		}
		void print(double i){
		cout << "print(double):" << i << endl;
		}
		void print(const char* i){
		cout << "print(char *):" << i << endl;
		}
};

int main()
{
	print_data ab;
	ab.print(2);
	ab.print(2.9);
	ab.print("dbng");
	cout << add(5) << endl;
	int a = 10;
	/*cout << add(a) << endl;error--有歧义*/
}
