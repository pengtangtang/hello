/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：struct_vector.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstdio>

typedef struct rect{
	int id;
	int length;
	int width;

	bool operator< (const rect &a) const
	{
		if(id != a.id)
			return id<a.id;
		else
		{
			if(length != a.length)
				return length<a.length;
			else
				return width<a.width;
		}

	}

}Rect;

int main()
{
	vector<Rect> vec;
	Rect rect;
	rect.id = 1;
	rect.length = 2;
	rect.width = 3;
	vec.push_back(rect);

	vector<Rect>::iterator it = vec.begin();
	cout << it->id << " " << it->length << " " << it->width << endl; 
	return 0;
}
