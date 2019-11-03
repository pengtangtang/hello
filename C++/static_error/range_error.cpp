/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：range_error.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <stdexcept>

int convert1(int *arr,int size,int n)
	throw (range_error)
{
	if(n<0)
		throw underflow_error("n is too small!");
	else
		throw overflow_error("n is too big! ");
	int i,j;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}

int convert(int *arr,int size,int n)
	throw (range_error)
{
	if(n<0 || n>size)
		throw range_error("n is too small or too big!");
	int i,j;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,1,2};
	int n;
	cin >> n;
#if 0
	try{
		convert(a,10,n);
	}catch(range_error &err){
		cout << "err:" << err.what() << endl;
		return -1;
	}

	try{
		convert1(a,10,n);
	}catch(overflow_error &err){
		cout << "err: " << err.what() << endl;
		return -1;
	}catch(underflow_error &err){
		cout << "err: " << err.what() << endl;
		return -1;	
	}
#else
	try{
		convert(a,10,n);
	}catch(runtime_error &err){//overflow_error underflow_error  都继承与runtime_error
		cout << err.what() << endl;
		return -1;
	}
#endif
	int i;
	for(i=0;i<10;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
