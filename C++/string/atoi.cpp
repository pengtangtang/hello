/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：atoi.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int my_atoi(const char* str)
{
	if(NULL == str)
		return 0;
	int ret = 0;
	while(0 != *str){
		ret = ret*10 + *str-'0';
		str++;
	}
	return ret;
}

int main()
{
	char str[100] = {0};
	cin.getline(str,sizeof(str));
	int ret = my_atoi(str);

	cout << "ret = " << ret << endl;
	return 0;
}
