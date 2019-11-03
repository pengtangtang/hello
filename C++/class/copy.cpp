/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：copy.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


void logCall(const string& funcName);

class Customer{
public:

	Customer(const Customer& rhs);
	Customer& operator=(const Customer& rhs);
private:
	string name;

};

Customer::Customer(const Customer& rhs):name(rhs.name)
{
	logCall("Customer copy constructor");
}

Customer& Customer::operator = (const Customer& rhs)
{
	logCall("Customer copy assignment operator");
	name = rhs.name;
	return *this;
}

void logCall(const string& funcName);
int main()
{
	return 0;
}
