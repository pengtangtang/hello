/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：const.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


class CTextBlock{
	public:
		size_t length() const;

	private:
		char* pText;
		size_t textLength;
		bool lengthIsValid;
};

size_t CTextBlock::length() const
{
	if(!lengthIsValid){
	mutable	textLength = strlen(pText);
	mutable	lengthIsValid = true;
	}
	return textLength;
}

int main()
{
	//const CTextBlock cctb("Hello");
	//char *pc = &cctb[0];

	//*pc = 'J';
	//cout << pc << endl;
	return 0;
}
