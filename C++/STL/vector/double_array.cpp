/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：double_array.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
//#include <cv.h>
#include <vector>

int main()
{
	int out[3][2]={1,2,3,4,5,6};

	vector<int*> v1;
	v1.push_back(out[0]);
	v1.push_back(out[1]);
	v1.push_back(out[2]);
	cout << v1[0][0] << endl;
	cout << v1[0][1] << endl;
	cout << v1[1][0] << endl;
	cout << v1[1][1] << endl;
	cout << v1[2][0] << endl;
	cout << v1[2][1] << endl;
}
