/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：copy_constructor_assignment.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


class Widget{
	public:
		Widget(){cout << "default\n";}
		Widget(const Widget &rhs){cout << "copy constructor\n";}
		Widget & operator = (const Widget &rhs){cout << "copy assignment\n";}
};

int main()
{
	Widget w1;
	Widget w2(w1);
	w1 = w2;
	Widget w3 = w1;
	return 0;
}
