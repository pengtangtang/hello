/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：derived_obj1.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class CShape{
	public:
		CShape(){m_color = 0;}
		~CShape(){}

		virtual void draw()
		{
			cout << "This is a shape\n";
			cout << m_color << endl;
		}

		double m_color;
};

class CRect:public CShape{
	public:
		CRect(){
			m_width = 5;
			m_height = 4;
			m_color = 1;
		}
		~CRect(){}

		double size()
		{
			return m_width*m_height;
		}
		virtual void draw()
		{
			cout << "This is rect\n";
			cout << m_color << endl;
		}

		double m_width;
		double m_height;
};

int main()
{
	CShape shp;
	shp.draw();

	CRect rect;
	rect.draw();
	cout << rect.size() << endl;
	return 0;
}
