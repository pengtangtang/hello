/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：friend_template.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

template <typename T>
class data{
public:
	data(T num){
		val = num;
	}
	T get_val()
	{
		return val;
	}
	template <typename C>
	friend C operator + (const data<C>& obj1,const data<C>& obj2);
private:
	T val;
};

template <typename C>
C operator + (const data<C>& obj1,const data<C>& obj2)
{
	return (obj1.val+obj2.val);
}

int main()
{
	data<int> obj1(8);
	data<int> obj2(2);

	int num = obj1+obj2;
	cout << "num:" << num << endl;
	return 0;
}
