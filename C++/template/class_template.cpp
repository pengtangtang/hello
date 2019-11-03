/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_template.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>

template<class T>
class Stack{
	private:
		vector<T> elems;
	public:
		void push(T const&);
		void pop();
		T top() const;
		bool empty() const{
			return elems.empty();
		}
};

template<class T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template<class T>
void Stack<T>::pop()
{
	if(elems.empty())
		throw out_of_range("Stack<>::pop():empty stack");;
	elems.pop_back();
}

template<class T>
T Stack<T>::top() const
{
	if(elems.empty())
		throw out_of_range("Stack<>::pop():empty stack");;
	return elems.back();
	
}

int main()
{
	try{
		Stack<int> intStack;
		Stack<string> stringStack;

		intStack.push(7);
		cout << intStack.top() << endl;

		stringStack.push("hello");
		cout << stringStack.top() << endl;

		stringStack.top();
		stringStack.top();

	}catch(exception const &ex){
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}
