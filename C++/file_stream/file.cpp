/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：file.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <fstream>

int main()
{
	char data[100];

	ofstream outfile;
	outfile.open("afile.dat");

	cout << "writing to file\n";
	cout << "enter your name";


	cin.getline(data,100);
	outfile << data << endl;

	cout << "enter your age: ";
	cin >> data;
//	cin.ignore();

	outfile << data << endl;

	ifstream infile;
	infile.open("afile.dat");

	cout << "reading from the file" << endl;

	infile.seekg(2);
	infile >> data;
	cout << data << endl;
	infile >> data;
	cout << data << endl;

	infile.seekg(2,ios::cur);
	infile >> data;
	cout << data << endl;
	infile >> data;
	cout << data << endl;
	infile.seekg(2,ios::end);
	infile >> data;
	cout << data << endl;
	infile >> data;
	cout << data << endl;
	infile.seekg(0,ios::end);
	infile >> data;
	cout << data << endl;
	infile >> data;
	cout << data << endl;

	infile.close();
	return 0;
}
