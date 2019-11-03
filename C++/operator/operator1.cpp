/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：operator1.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
class Integer{
	public:
		Integer(int num=0):val(num){}
		void setVal(int num=10){
			val = num;
		}
		int getVal(){
			return val;
		}
		Integer operator ++(int);
		Integer &operator += (const Integer &obj);

#if 0
		friend int operator + (const Integer &obj1,const Integer &obj2)
#else
		Integer operator + (const Integer &obj1);
#endif
	private:
		friend Integer &operator ++ (Integer &obj);
		int val;
};

#if 0
int operator + (const Integer &obj1,const Integer &obj2)
{
	return (obj1.val + obj2.val)
}
#else
Integer Integer::operator + (const Integer &obj1)
{
	Integer obj(this->val+obj1.val);
	return obj;
}
#endif

Integer &Integer::operator += (const Integer &obj)
{
	this->val += obj.val;
	return (*this);
}

Integer &operator ++(Integer &obj)
{
	++obj.val;
	return obj;
}

Integer Integer::operator ++ (int)
{
	Integer obj1(this->val);
	this->val++;
	return obj1;
}

int main()
{
	Integer obj(5);
	obj++;
	
	cout << "obj: " << obj.getVal() << endl;

	Integer obj1;
	obj1 = obj++;
	obj1 += obj;
	cout << "obj: " << obj.getVal() << endl;
	cout << "obj1: " << obj1.getVal() << endl;
	
	return 0;
}
