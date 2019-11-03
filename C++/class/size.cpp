/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：size.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class c_null{};
class c_null2{
	public:
		c_null2(){}
};
int main()
{
	cout << sizeof(c_null) << endl;
	cout << sizeof(c_null2) << endl;
	return 0;
}
