/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：m_struct.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

void print_book(struct Books *book);
struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
#if 0
int main()
{
	struct Books book1;
	struct Books book2;

	strcpy(book1.title,"c++");
	strcpy(book1.author,"ya");
	strcpy(book1.subject,"programing");
	strcpy(book2.title,"c");
	strcpy(book2.author,"yaa");
	strcpy(book2.subject,"y programing");

	cout << "book1.title:" << book1.title << endl;
	cout << "book1.author:" << book1.author << endl;
	cout << "book1.subject:" << book1.subject << endl;

	return 0;
}
#else
	
int main()
{

	struct 	Books book1,book2;

	strcpy(book1.title,"c++");
	strcpy(book1.author,"ya");
	strcpy(book1.subject,"programing");
	book1.book_id = 9090; 

	strcpy(book2.title,"c");
	strcpy(book2.author,"yaa");
	strcpy(book2.subject,"y programing");
	book2.book_id = 9091; 

	print_book(&book1);
	return 0;
}

void print_book(struct Books *book)
{

	cout << "book1.title:" << book->title << endl;
	cout << "book1.author:" << book->author << endl;
	cout << "book1.subject:" << book->subject << endl;
	cout << "book1.book_id:" << book->book_id << endl;
}
#endif
