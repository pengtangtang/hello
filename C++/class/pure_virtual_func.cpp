/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pure_virtual_func.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Shape{
	public:
		Shape(int a = 0):id(a){}
		virtual void draw() const = 0;
		virtual void error(const string &msg){}
		int objectID() const{
			return id;
		}
	private:
		const int id;
};

class Rectangle : public Shape{
	public:
		Rectangle(int a = 1):id(a){}
		void draw()const{
		cout << id << endl;
		cout << "Rectangle draw\n";
		}

		void error(const string &msg){
		cout << "Rectangle error\n";
	}
	private:
	 const int id ;
};

class Ellipase : public Shape{
	public:
		Ellipase(int a = 2):id(a){}
		void draw()const{
			cout << id << endl;
		cout << "Ellipase draw\n";
		}

		void error(const string &msg){
		cout << "Ellipase error\n";
		}
	private:
	const int id ;
};

int main()
{
	//Shape *ps = new Shape;error--含pure func为抽象类不能有具体的对象
	Shape *ps1 = new Rectangle;
	ps1->draw();
	Shape *ps2 = new Ellipase;
	ps2->draw();
//	ps1->Shape::draw();error----Shape::draw()没有定义，不能调用
//	ps2->Shape::draw();
	return 0;
}
