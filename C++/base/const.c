/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：const.c
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
	const int i = 2;/*i 应该被初始化 否则编译器自动初始化为随机值*/
	printf("i = %d\n",i);
       /*i = 100;i readonly*/
	int *p = (int *)&i;
	*p = 100;/*可以通过地址间接改变const变量的值*/
	printf("i = %d\n",i);
	return 0;

}
