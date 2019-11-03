/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：atoi_sample.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <limits.h>

#define NULL_PTR_ERR 1
#define ERANGE 2
int err_code = 0;

int my_atoi(const char *);
int main()
{
	int result = my_atoi("-");
	cout << "result:" << result << endl;
	cout << "err_code:" << err_code << endl;

	result = my_atoi("    ");
	cout << "result:" << result << endl;
	cout << "err_code:" << err_code << endl;
	result = my_atoi("-1");
	cout << "result:" << result << endl;
	cout << "err_code:" << err_code << endl;
	result = my_atoi("+123");
	cout << "result:" << result << endl;
	cout << "err_code:" << err_code << endl;
	result = my_atoi("-11111111111111111111111111111111111111111");
	cout << "result:" << result << endl;
	cout << "err_code:" << err_code << endl;
	return 0;
}

int my_atoi(const char *s)
{
	int negative = 0;
	char c = 0;
	long long ret = 0;
	err_code = 0;

	if(NULL == s){
		err_code = NULL_PTR_ERR;
		return 0;
	}

	while(' ' == *s)
		s++;

	if(0 == *s)
		return 0;
	if('-' == *s)
	{
		negative = 1;
		s++;
	}
	else if('+' == *s)
	{
		negative = 0;
		s++;
	}
	else
		return 0;
	while(isdigit(*s))
	{
		ret = ret*10+*s-'0';
		if(ret>(negative?-(long long)INT_MIN:INT_MAX))
		{
			err_code = ERANGE;
			return negative?INT_MIN:INT_MAX;
		}
		s++;
	}
	return negative? -ret:ret;
}
