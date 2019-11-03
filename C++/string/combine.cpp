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
	str3 += str;
	str2 += "ni hao\n";
	str1.append(str);
	str.append("i want to");
	str.push_back('a');

	cout << str << endl;

	int len = str.size();
	int len1 = str1.size();
	int len2 = str2.size();
	int len3 = str3.length();

	cout << "len: " << len << ","
		<< "len1: " << len1 << ","
		<< "len2: " << len2 << ","
		<< "len3: " << len3 << endl;
	return 0;
}
