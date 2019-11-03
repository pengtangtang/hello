/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：untypedefine_template.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

#if 0
template <typename T,int size>
T array_sum(T *p)
{
	T sum = 0;
	int i;
	for(i=0;i<size;i++){
		sum += p[i];
	}
	return sum;
}
#else
template <typename T = int,int size = 2>
T arr_sum(T *p){
	T sum = 0;
	int i;
	for(i=0;i<size;i++)
		sum += p[i];
	return sum;
}
#endif
template <typename T,int size>
class array{
public:
	array(T data){
		arr = new T[size];
		int i;
		for(i=0;i<size;i++)
			arr[i] = data;
	}
	~array(){
	delete [] arr;
	}

	void get_arr(){
		int i;
		cout << "arr:";
		for(i=0; i<size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

private:
	T *arr;
};

int main()
{
#if 1
	int a2[2] = {1,2};
	int su = arr_sum<int>(a2);
	cout << "su:" << su << endl;
#else
	array<int,10> obj(1);
	obj.get_arr();

	array<char,2> obj1('q');
	obj1.get_arr();

	array<double,2> obj2(1.1);
	obj2.get_arr();
	int a[] = {1,2,3,4,5,6,7,8,9,0};

	int sum = array_sum<int,10>(a);
	cout << sum << endl;
	double b[5] = {9.0,7.8,9.6,5.6,8.8};
	double  sum1 = array_sum<double,5>(b);
	cout << sum1 << endl;

#endif
	return 0;
}
