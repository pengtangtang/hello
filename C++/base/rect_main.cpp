/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：rect_main.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "rect.h"

int main()
{
	my_rect obj;
	obj.set_rect(1,2);

	cout << "obj.area:" << obj.get_area() << endl;
	cout << "obj.length:" << obj.get_length() << endl;
}
