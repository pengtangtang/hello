/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：operator.cpp
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
class box{
public:
	double get_volume()
	{
		return length*breadth*height;
	}

	void set_length(double len)
	{
		length = len;
	}

	void set_breadth(double bre)
	{
		breadth = bre;
	}
	void set_height(double hei)
	{
		height = hei;
	}

	box operator+(const box& b){
		box obj;
		obj.length = this->length+b.length;
		obj.breadth = this->breadth+b.breadth;
		obj.height = this->height+b.height;
		return obj;
	}

private:
	double length;
	double breadth;
	double height;
};

int main()
{
	box box1;
	box box2;
	box box3;
	double volume = 0.0;

	box1.set_length(2.3);
	box1.set_breadth(9.8);
	box1.set_height(3.4);
	box2.set_length(2.3);
	box2.set_breadth(9.8);
	box2.set_height(3.4);

	volume = box1.get_volume();
	cout << "box1.volume：" << volume << endl;

	box3 = box1+box2;
	volume = box3.get_volume();
	cout << "box3.volume: " << volume << endl;

	return 0;
}
#else

template <typename T>
class test{
public:
	void set_val(T num){
		val = num;
	}

	T get_val(){
		return val;
	}

	test& operator ++()
	{
		this->val++;
		return *this;
	}

	test operator ++(int)
	{
		test obj = *this;
		this->val++;
		return obj;
	}
private:
	T val;
};

template <typename T>
class distance1{
	private:
		T feets;
		T inches;
	public:
		distance1(){
			feets = 0;
			inches = 0;
		}
		distance1(int f,int i)
		{
			feets = f;
			inches = i;
		}

		void display_distance(){
			cout << "feets:" << feets << "distance："<< inches << endl; 
		}

		distance1& operator -()
		{
			feets = -feets;
			inches = -inches;
			return *this;
		}

		bool operator < (const distance1& d){
			if(feets < d.feets)
				return true;
			if(feets==d.feets && inches<d.inches)
				return true;
			return false;
		}
/*输入输出运算符可以用于内置的数据类型，可以通过重载，操作对象等用户自定义数据类型。
 * 需要将输入输出运算符重载函数声明为类的友元函数，这样就可以不用创建对象二
 * 直接调用*/
		friend istream& operator >> (istream &input,distance1 &d)
		{
			input >> d.feets >> d.inches;
			return input;
		}

		friend ostream& operator << (ostream &output,const distance1 &d){
		output << "f: " << d.feets << "i:" << d.inches;
		return output;
		}

		distance1 operator()(int a,int b,int c)
		{
			distance1<T> d;
			d.feets = a+b+10;
			d.inches = b+c+100;
			return d;
		}
};

int main()
{
#if 0
	test<int> obj;
	obj.set_val(9);
	obj++;
	test<int> obj1;
	obj1 = obj++;
	++obj;
	cout << "obj.val: " << obj.get_val() << endl; 
	cout << "obj1.val: " << obj1.get_val() << endl; 
	
	distance1<int> d1(11,12),d2(32,31),d3;
	if(d1 < d2)
		cout << "d1 < d2\n";
	cout << "d1 not less than d2\n";

	cin >> d3;
	cout << "d3 distance: " << d3 << endl;
#else
	distance1<int> d1(11,12),d2;

	cout << "first distance:" ;
	d1.display_distance();

	d2 = d1(10,10,10);
	cout << "first distance:" ;
	d2.display_distance();
#endif
	return 0;
}


#endif
