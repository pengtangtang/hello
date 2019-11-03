/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：arry.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	int ROW = 2;
	int COL = 3;
	double **pvalue = new double*[ROW];

	for(int i = 0;i<COL;i++)
		pvalue[i] = new double[COL];

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			pvalue[i][j] = j;
			cout << pvalue[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i=0;i<COL;i++)
		delete[] pvalue[i];
	delete[] pvalue;
	return 0;
}
