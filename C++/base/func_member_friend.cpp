/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：func_member_friend.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


class integer;

class test{
	public:
		void set_val(integer &obj,int num);
		int get_val(integer &obj);
		void func(integer &obj)
		{
			/*cout << obj.val << endl;*/
		}
};

class integer{
public:
	integer(int num=0):val(num){}
private:
	friend void test::set_val(integer &obj,int num);
	friend int test::get_val(integer &obj);
	int val;
};

void test::set_val(integer &obj,int num)
{
	obj.val = num;
}

int test::get_val(integer &obj)
{
	return obj.val;
}

int main()
{

	integer obj;
	test t1;
	cout << t1.get_val(obj) << endl;
	t1.set_val(obj,100);
	cout << t1.get_val(obj) << endl;
	return 0;
}
