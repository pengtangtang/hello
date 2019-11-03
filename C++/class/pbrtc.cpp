/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pbrtc.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Person{
	public:
		Person(){cout << "Per\n";}
		virtual ~Person(){cout << "~Per\n";}
	private:
		string name;
		string address;
};
class Student:public Person{
	public:
		Student(){cout << "Stu\n";}
		~Student(){cout << "~Stu\n";}
	private:
		string schoolName;
		string schoolAddress;
};

bool validateStudent(const Student &s)
{
	return  true;
}

int main()
{
	Student plato;
	bool platoIsOk = validateStudent(plato);
	cout << platoIsOk << endl;
	return 0;
}
