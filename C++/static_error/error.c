/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：error.c
*   创 建 者：pengtangtang
*   创建日期：2019年10月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>


int readfile(const char *file,void *buf,int size)
{
	FILE *fp = fopen(file,"r");
	if(NULL == fp)
		return -1;
	int ret = fseek(fp,12,SEEK_END);
	if(0 > ret)
		goto ERR_STEP;
	ret = fread(buf,size,1,fp);
	if(1 != ret){
		ret = -1;
		goto ERR_STEP;
	}
ERR_STEP:
	fclose(fp);
	return ret;
}

int main()
{
	char buf[1024] = {0};
	readfile("error.c",buf,sizeof(buf));
	return 0;
}
