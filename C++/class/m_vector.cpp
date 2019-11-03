/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：m_vector.cpp
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

template<typename T,typename Alloc>
bool vector::operator != (typename const vector <T,Alloc>::iterator &lhs,typename const vector<T,Alloc>::iterator &rhs)
{
	return (*lhs==*rhs);
}

int main()
{
	vector<int> vec;
	int i;

	cout << "vec size = " << vec.size() << endl;

	for(i=0; i<5; i++){
	vec.push_back(i);
	}

	cout << "vec size = " << vec.size() << endl;
	for(i=0; i<5; i++){
		cout << "value of vec["<< i << "] = " << vec[i] << endl;
	}

	vector<int>::iterator v = vec.begin();
	while(v != vec.end)
	{
		cout << "vlue of v = " << *v << endl;
		v++;
	}


	return 0;
}
