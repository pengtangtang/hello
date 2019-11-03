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
#include <deque>
#include <iostream>
#define NUMMAX 6

int main()
{
#if 0
	int i;
	deque<int> one;
	for(i=0;i<NUMMAX;i++)
		one.push_front(i);

	deque<int>::reference refer = one.front();
	for(i=0;i<one.size();i++){
		cout << "no:" << i << ":" << refer << endl;
		refer++;
	}
	one.pop_back();
	one.pop_back();
	one.pop_back();
	refer = one.front();
	for(i=0;i<one.size();i++){
		cout << "no:" << i << ":" << refer << " ";
		refer++;
	}
	refer = one.back();
	cout << "back:" << refer << endl;
	refer = one.front();
	cout << "back:" << refer << endl;
#else
	deque<int> d = {7,5,16,8};

	d.push_front(13);
	d.push_back(25);

	for(int n : d)
		cout << n << endl;
#endif
	return 0;
}
