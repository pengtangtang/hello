/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：name_space.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

namespace first_space{
	void func(){
		cout << "inside first_space\n"; 
	}
namespace second_space{
	void func(){
		cout << "second——space\n";
	}
}
}

using namespace first_space::second_space;

int main()
{
	/*first_space::func();*/
	func();
	/*second_space::func();*/
	return 0;
}
