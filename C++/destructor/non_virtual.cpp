/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：non_virtual.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Transaction{
public:
	Transaction();
	virtual void logTransaction() const = 0 ;
};

void Transaction::logTransaction() const
{

}

Transaction::Transaction()
{
	cout << "Transaction\n";
	logTransaction() ;
}

class BuyTransaction:public Transaction{
	public:
		virtual void logTransaction() const{}
};

class SellTransaction:public Transaction{
public:
	virtual void logTransaction() const{}
};

int main()
{
	BuyTransaction b;
	return 0;
}
