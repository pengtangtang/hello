/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：iterator.cpp
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

int main()
{

	vector<int> vec = {1,2,3,4,5,6,7};
	if(vec.empty())
		cout << "size:" << vec.size() << endl;
	else 
		cout << "max_size: " << vec.max_size() << endl;

	cout << *(vec.begin()) << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	cout << *(vec.data()) << endl;
	//cout << vec << endl;

	vec.push_back(100);
	//cout << vec << endl;

	const vector<int>::iterator iter = vec.end();//==T*const
	*iter = 10;
	//++iter;
	vector<int>::const_iterator cIter = vec.begin();//==const T*
	//*cIter = 10;
	cout << *cIter << endl;
	++cIter;
	cout << *cIter << endl;

	vec.push_back(25);
	vec.push_back(13);
	for(int n : vec)
		cout << n << " ";
	cout << endl;

	return 0;
}
