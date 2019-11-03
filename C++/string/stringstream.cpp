/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：stringstream.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstdio>

int main()
{/*stringstream比sprintf sscanf更安全，不会产生数组溢出问题，但需要使用clear()释放内存*/
	ostringstream os;
	float fval = 123.0;
	os << fval;
	cout << os.str() << endl;
	os.clear();

	istringstream is("123.0");
	is >> fval;
	cout << fval << endl;
	is.clear();

	int H,M,S;
	string time_str;
	long seconds = 12345469;
	H = seconds/3600;
	M = seconds%3600/60;
	S = seconds%3600&60;
	char ctime[10];

	sprintf(ctime,"%d:%d:%d",H,M,S);//将数字转换为字符串,把格式化的数据写到某个字符串中
	time_str = ctime;
	cout << "time_str:" << time_str << endl;

	char str[] = "15.455";
	int i;
	float fp;
	sscanf(str,"%d",&i);//读取格式化的数据写入变量中
	sscanf(str,"%f",&fp);
	printf("intefer:%d\n",i+1);
	printf("rea:%f\n",fp+1);

	return 0;
}
