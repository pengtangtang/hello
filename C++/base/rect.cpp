/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：rect.cpp
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

void my_rect::set_rect(int a,int b){
	h = a;
	w = b;
}

int my_rect::get_area()
{
	return (h*w);
}

int my_rect::get_length()
{
	return (2*(h+w));
}
