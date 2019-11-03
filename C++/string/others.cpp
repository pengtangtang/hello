/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：others.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <string>
#include <iostream>

int main()
{
	string str;
	getline(cin,str);

	if(str.empty())
		cout << "cin faile\n";
	string str1("hell");
	str.swap(str1);

	cout << "str:" << str << endl;
	cout << "str1:" << str1 << endl;

	return 0;
}
