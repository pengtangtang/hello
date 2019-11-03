/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：define.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <list>
#include <iostream>
#include <iterator>
#define NUMMAX 6

int main()
{
	int i;
	list<int> one;
	for(i=0;i<NUMMAX;i++)
		one.push_front(i);

	list<int>::iterator ptr = one.begin();
	for(i=0;i<one.size();i++){
		cout << "no:" << i << ":" << *ptr << endl;
		ptr++;
	}
	list<int>::iterator start;
	start = one.begin();
	for(i=0;i<NUMMAX;i++)
		start++;

	list<int>::iterator end;
	end = start;
	for(start=one.begin();start != one.end();)	{
		one.erase(start++);
	}
/*	for(i=0;i<one.size();i++){
		cout << "no:" << i << ":" << *ptr << " ";
		ptr++;
	}*/
	return 0 ;
}
