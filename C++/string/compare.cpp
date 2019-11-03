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
#if 0
	int f1 = str2.find('p');
	cout << "f1: " << f1 << endl;
	int f2 = str2.find(str1,3);
	cout << "f2: " << f2 << endl;
	int f3 = str2.find("987",3,4);
	cout << "f3: " << f3 << endl;
	int f4 = str2.rfind("a",3);
	cout << "f4: " << f4 << endl;
	int f5 = str2.rfind("ni hao");
	cout << "f5: " << f5  << endl;
#else
	size_t cat_pos = str2.rfind("pp");
	if(cat_pos != string::npos)
		cout << "cat_pos:" << cat_pos << endl;
	cout << "pp is not in str2\n";
#endif
	size_t pos = str2.find_first_of("ijwno");
	if(pos == string::npos)
		cout << "匹配失败\n";
	else
		cout << "在位置" << pos << "匹配到\n";

	cout << str2 << endl;
	cout << str2[11] << endl;
	cout << str2.at(5) << endl;

	return 0;
}
