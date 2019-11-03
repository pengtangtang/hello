/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：template.cpp
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
T add(T a,T b)
{
	return a+b;
}
template <typename T,typename H>
T add1(T a,H b)
{
	return a+b;
}

template <typename T>
class data{
public:
	data(T num){
	val = num;
	}
	void set_val(T num){
	val = num;
	}
	T get_val();
private:
	T val;
};

template <typename T>
T data<T>::get_val()
{
	return val;
}

int main()
{
	data<int> obj(5);
	cout << obj.get_val() << endl;
	data<char> obj1('d'); 
	cout << obj1.get_val() << endl;
	cout << add(9,8) << endl;
	cout << add(6.7,9.0) << endl;
	cout << add1(6,9.0) << endl;
	return 0;
}
