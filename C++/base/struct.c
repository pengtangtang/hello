/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：struct.c
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


struct STU{
	char name[20];
	int id;
	int age;
};

int main()
{
	struct STU stu = {
	.name = "xiao min",
	.id = 1,
	.age = 12
	};
	printf("stu.name = %s\n",stu.name);
	return 0;
}
