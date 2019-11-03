/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：vector.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月22日
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
	vector<int> vec;
	int i;

	cout << "vector size = " << vec.size() << endl;

	for(i=0; i<5; i++){
		vec.push_back(i);
	}
	cout << "vector size = " << vec.size() << endl;

	for(i=0; i<5; i++){
		cout << "value of vec[" << i << "] = " << vec[i] << end;
	}

	vector<int>::iterator v = vec.begin();
	while(v != vec.end()){
	cout << "value of v = " << *v << endl;
	v++;
	}
	return 0;

}
