/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：const.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	volatile const int i = 0;/*严格的类型检查，const变量必须被初始化
	const定义的变量直接从寄存器中取，导致改变没有成功，需要防止优化*/
	cout << i << endl;

	int *p = (int *)&i;
	cout << "p = " << p << ",i = " << i << endl;
	*p = 100;
	cout << "*p = " << *p << ",i = " << i << endl;
	
	return 0;
}
