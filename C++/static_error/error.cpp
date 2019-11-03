/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：error.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <stdexcept>
/*
int exceptionfordiv(int x,int y)
	throw (invalid_argument)
{
	if(0==y)//抛出异常
		throw invalid_argument("Divisor is zero!");
	return x/y;
}
int main()
{
	int a,b;
	cin >> a >> b;
	int num = 0;
	try{//检查异常
		num = exceptionfordiv(a,b);
	}catch (invalid_argument &err){//捕获异常
		cout << err.what() << endl;
		return -1;
	}
	cout << "num: " << num << endl;
	return 0;
}*/

int exceptionfordiv(a,b)
	throw (invalid_argument)//所有的标准异常类都继承于exception
{
	if(0 == y)
		throw invalid_argument("Divisor is zero!");
	return x/y;
}

int main()
{
	int a,b;
	cin >> a >> b;
	int num = 0;
	try{
		num = exceptionfordiv(a,b);
	}catch(invalid_argument &err){
		cout << err.what() << endl;//标准异常类中成员函数what()用来显示错误信息
		return -1;
	}
	cout << "num: " << num << endl;
	return 0;
}
