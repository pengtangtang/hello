/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：enum_hack.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
/*
class Game{
	private:
		static const int GameTurn = 10;
		int scores[GameTurn];
};
*/
class Game{
	private:
		/*static const int GameTurn ;*/
		enum {GameTurn = 10};
		int scores[GameTurn];
};
/*const int Game::GameTurn = 10*/;
int main()
{

	return 0;
}
