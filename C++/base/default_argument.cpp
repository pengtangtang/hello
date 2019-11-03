/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：default_argument.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#if 0
int add(int a,int b,int c = 1);

int main()
{
	cout << add(1,2) << endl;
	return 0;
}

int add(int a,int b,int c){
	return a+b+c;
}
#else
int add(int a,int b,int c = 1)
{
	return (a+b+c);
}

int main()
{
	cout << add(1,2) << endl;
	return 0;
}


#endif
