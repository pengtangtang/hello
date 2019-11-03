/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：rect.h
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _RECT_H
#define _RECT_H

class my_rect{
public:
	void set_rect(int,int);
	int get_area();
	int get_length();
private:
	int h;
	int w;
};

#endif
