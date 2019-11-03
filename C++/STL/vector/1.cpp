/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：1.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

bool Comp(const int &a,const int &b)
{
	return a > b;
}//重写排序比较，按降序

int main()
{
	vector<int> vec;
	vec.push_back(12);
	cout << vec[0] << endl;

	vector<int>::iterator it;

	for(it=vec.begin();it != vec.end();it++)
		cout << *it << endl;

	vec.insert(vec.begin()+0,31);
	cout << *(vec.begin()) << " " << *(vec.end()) << endl;
	cout << vec.back() << " " << vec.front() << endl;
	cout << vec[0] << endl;
	vec.erase(vec.begin());
	cout << vec[0] << endl;

	vector<int> v={1,2,3,4,2,3,9};
/*	for(int n : v)
		cout << n << "\n";
	v.erase(v.begin()+1,v.end()-2);
	v.erase(v.begin());
	for(int n : v)
		cout << n << "\n";*/
	vec.clear();
	reverse(v.begin(),v.end());
	sort(v.begin(),v.end(),Comp);
	for(int n : v)
		cout << n << " ";
	cout << endl;
	sort(v.begin(),v.end());
	/*for(int n : v)
		cout << n << " ";
	cout << endl;*/
	int size = v.size();
	for(int i=0;i<size;i++)
		cout << v[i] << " ";
	cout << endl;
	for(int i=0;i<size;i++)
		cout << v.at(i) << " ";
	cout << endl;
	cout << vec.size() << "," << v.size() << endl;
	return 0;
}
