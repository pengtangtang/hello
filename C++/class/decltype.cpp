/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：decltype.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月30日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{
	int i = 4;
	int arr[5] = {0};

	int *ptr = arr;
	struct S{
		double d;
	}s;
	void over_load(int);
	void over_load(char);
	int && rval_ref();
	const bool func(int);

	decltype (arr) var1;
	decltype (ptr) var2;
	decltype (s.d) var3;

	decltype (rval_ref()) val5 = 1;

	decltype ((i)) val6 = i;
	decltype (true ? i:i) var7 = i;
	decltype (++i) var8 = i;
	decltype (arr[5]) var9 = i;
	decltype (*ptr) var10 = i;
	decltype ("hello" var11 = "hello");

	decltype(1) var12;
	decltype(func(1)) var13 = true;
	decltype(i++) var14 = i;


	return 0;
}
