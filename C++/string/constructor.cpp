/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：constructor.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include<string>

int main()
{
	string str("tang tang");
	string str1(10,'a');
	string str2(str1);
	string str3;
	str3 = str2;

	cout << "str: " << str << ","
		<< "str1: " << str1 << ","
		<< "str2: " << str2 << ","
		<< "str3: " << str3 << endl;
	return 0;
}
