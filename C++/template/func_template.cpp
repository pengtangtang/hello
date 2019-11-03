/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：func_template.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>

template<typename T>
inline T const& Max(T const& a,T const &b)
{
	return a<b ? b:a;
}

int main()
{
	int i = 39;
	int j = 28;

	cout << Max(i,j) << endl;

	double f1 = 12.3;
	double f2 = 43.12;
	cout << Max(f1,f2) << endl;

	string s1 = "hello";
	string s2 = "word";
	cout << Max(s1,s2) << endl;

	return 0;
}
