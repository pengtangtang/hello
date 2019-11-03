/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：object.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Box{
public:
	Box(){
		cout << "调用构造函数！" << endl;
	}
	~Box(){
		cout << "调用析构函数！" << endl;
	}


};

int main()
{
	Box* myBoxArray = new Box[4];

	delete [] myBoxArray;

	return 0;
}
