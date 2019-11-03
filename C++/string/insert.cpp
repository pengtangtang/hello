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
	string::iterator it;
	str3 = str2;
	str3 += str;
	str2 += "ni hao\n";
	str1.append(str);
	str.append("i want to");
	str.push_back('a');
	str2.insert(0,"ssss");
	cout << str2 << endl;
	str2.insert(2,"ssss");
	cout << str2 << endl;
	str2.insert(9,8,'s');
	cout << str2 << endl;

	str2.erase(5,6);
	cout << str2 << endl;

	it = str2.begin()+9;
	str2.erase(it);
	cout << str2 << endl;
	str2.erase(str2.begin(),str2.end()-6);
	cout << str2 << endl;
	str2.erase(it,str2.end()-6);
	cout << str2 << endl;

	return 0;
}
