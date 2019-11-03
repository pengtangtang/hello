/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：move.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <stdio.h>
#include <errno.h>

int main()
{
	double * pvalue = NULL;
	if(!(pvalue = new double))
		perror("new");
	*pvalue = 29494.99;
	cout << *pvalue << endl;

	delete pvalue;
	return 0;
}
