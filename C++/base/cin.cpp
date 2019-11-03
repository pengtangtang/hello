/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：cin.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{/*输入数据时字符串的常量相互影响，最好分开输入*/
#if 0
	char a;
	int b;
	double c;
	char buf[10];
	cin  >> a >> b >> c;//会将空格作为一个输入数据
	cout << a << b << c << endl;
	cin.getline(buf,10);
	cout << "buf:" << buf << endl;
#else 
	string str;
	getline(cin,str);

	cout << "str:" << str << endl;
	str += "word";
	cout << "str:" << str << endl;
#endif
	return 0;
}
