/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：operator.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cassert>
class Array{
	public:
		Array(int num = 10){
			assert(num > 0);
			size = num;
			arr = new int[size];
			int i;
			for(i=0; i<size; i++)
				arr[i] = i+1;
		}
		~Array(){
			delete [] arr;
		}

		void getArray(){
			int i;
			for(i=0; i<size; i++)
				cout << arr[i] << " ";
			cout << "\n";
		}
		int operator [] (int);
	private:
		int *arr;
		int size;
};

int Array::operator [] (int num)
{
	if(num < 0 || num > size)
		return -1;
	return this->arr[num];
}

int main()
{
	Array obj;
	obj.getArray();

	cout << obj[5] <<endl;
	return 0;
}
