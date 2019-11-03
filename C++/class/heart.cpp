/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：heart.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{
	int i,j,k,l,m;
	char c = '*';
	for(i=1;i<=5;i++)
		cout << endl;
	for(i=1;i<=3;i++){
		for(j=1;j<=32-2*i;j++)	cout<<" ";
		for(k=1;k<=4*i+1;k++) cout<<c;
		for(l=1;l<=13-4*i;l++) cout<<" ";
		for(m=1;m<=4*i+1;m++) cout<<c;
		cout<<endl;
	}

	for(i=1;i<=3;i++){
		for(j=1;j<=24+1;j++) cout<<" ";
		for(k=1;k<=29;k++) cout<<c;
		cout << endl;
	}

	for(i=7;i>=1;i--){
		for(j=1;j<=40-2*i;j++) cout<<" ";
		for(k=1;k<=4*i-1;k++) cout<<c;
		cout << endl;
	}

	for(i=1;i<=39;i++){
		cout << " ";
	}
	cout << c << endl;
	for(i=1;i<=5;i++) cout << endl;
	return 0;
}
