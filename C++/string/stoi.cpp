/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：stoi.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>

int main()
{
	cout << stof("123.0") << endl;
	size_t pos;
	cout << stof("123.01ewrq",&pos) << endl;
	cout << "pos:" <<  pos << endl;
	cout << to_string(123.0) << endl;
	return 0;
}
