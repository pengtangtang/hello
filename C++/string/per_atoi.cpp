/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：per_atoi.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <limits.h>

int flag = 0;

int my_atoi(const char *);

int main()
{
	char s[100] = {0};
	cin.getline(s,sizeof(s));

	int a = my_atoi(s);
	cout << "a=" << a << endl;

	return 0;
}

int my_atoi(const char *str)
{
	if(str == NULL)
		return -1;
	int ret = 0;
	while(*str == ' ')//如果开头有空格
		str++;
	if(*str == '-')
	{
		flag = 1;
		str++;
	}

	while(0 != *str){
		if(*str<'0'|| *str>'9')
		{
			str++;
			continue;
		}
		ret = ret*10+*str-'0';
		str++;
	}
	if(flag)
		ret = -ret;
	if(ret<INT_MIN || ret>INT_MAX)
		return -2;
	return ret;
}
