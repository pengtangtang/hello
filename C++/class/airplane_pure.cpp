/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：airplane_pure.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Airport{};

class Airplane{
public:
	virtual void fly(const Airport& destination) = 0;
};

void Airplane::fly(const Airport& destination)
{

}

class ModelA:public Airplane{
	public :
		virtual void fly(const Airport& destination)
		{
			Airplane::fly(destination);
		}
};
class ModelB:public Airplane{
	public :
		virtual void fly(const Airport& destination)
		{
			Airplane::fly(destination);
		}
};
class ModelC :public Airplane{
	public :
		virtual void fly(const Airport& destination)
		{
			cout << "C\n";
		}
};
int main()
{

	Airport a;
	ModelC c;
	c.fly(a);
	return 0;
}
