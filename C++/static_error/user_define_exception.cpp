/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：user_define_exception.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <exception>

class myexception:public exception{
	public:
		myexception(const char *str) noexcept;
		virtual ~myexception() noexcept;
		const char* what() noexcept;
	private:
		const char *errmsg;
};

myexception::myexception(const char *str) noexcept
{
	errmsg = str;
}

myexception::~myexception() noexcept
{

}

const char* myexception::what() noexcept
{
	return errmsg;
}

int exceptionfordiv(int x,int y)
	throw (myexception)
{
	if(0 == y)
		throw myexception("divisor is zero");
	return x/y;
}

int main()
{
	int a,b;
	int num = 0;
	cin >> a >> b;
	try{
		num = exceptionfordiv(a,b);
	}catch(myexception &err){
		cout << err.what() << endl;
		return -1;
	}
	cout << "num: " << num << endl;
	return 0;
}
