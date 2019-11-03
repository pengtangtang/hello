/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：vir_destructor.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class TimeKeeper{
	public:
		TimeKeeper();
		~TimeKeeper();
};

class AutomicClock:public TimeKeeper{};
class WaterClock:public TimeKeeper{};
class WristClock:public TimeKeeper{};

int main()
{
	return 0;
}
