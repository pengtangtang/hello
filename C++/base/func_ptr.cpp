/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：func_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>
typedef int(*pf)(const int& a,const int& b);

int sum(const int& a,const int& b){
	return (a+b);
}

int Minus(const int& a,const int& b){
	return (a-b);
}

int do_something(const int& a,const int& b,pf p){
	return p(a,b);
}

int main()
{
	cout << do_something(1,2,&sum) << endl;
	cout << do_something(1,2,&Minus) << endl;
	system("pause");
	return 0;
}
