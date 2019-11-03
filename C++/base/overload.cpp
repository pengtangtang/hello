/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：overload.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdio>
typedef double(*p)(double);
typedef int(*p1)(int);
typedef int(*p2)(int,int);
typedef int(*p3)(int,int,int);
/*重载函数在汇编代码中的函数名是不一样的*/
int add(int a){
	cout << "add(int)\n";
	p1 addr1 = add;
	printf("add(int) = %p\n",addr1);
	return a+a;
}
#if 0
double add(int a){/*error:重载只和函数名 参数 有关 与返回值无关*/
	return double(a+a);
}
#else
double add(double a){
	cout << "add(double)\n";
	p addr = add;
	printf("add(double) = %p\n",addr);
	return a+a;
}
#endif

int add(int a,int b){
	/*p addr = add;
	printf("%p\n",addr);*/
	cout << "add(int,int):"   << endl;
	p2 addr2 = add;
	printf("add(int,int) = %p\n",addr2);
	return a+b;
}

int add(int a,int b,int c){
	cout << "add(int,int,int)\n";
	p3 addr3 = add;
	printf("add(int,int,int) = %p\n",addr3);
	return a+b+c;
}

typedef int(*q)();
int main()
{
	q addr = main;
	printf("main = %p\n",main);
	cout << add(4) << endl;
	cout << add(4.0) << endl;
	cout << add(4,6) << endl;
	cout << add(4,4,5) << endl;
	return 0;
}
