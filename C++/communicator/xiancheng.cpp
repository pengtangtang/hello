/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：xiancheng.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <pthread.h>
#include <cstdlib>

#define NUM_THREADS  5

#if 0
void *say_hello(void *arg)
{
	cout << "Hello\n";
}

int main()
{
	pthread_t tids[NUM_THREADS];
	for(int i=0;i<NUM_THREADS;i++){
		int ret = pthread_create(&tids[i],NULL,say_hello,NULL);
		if(0 != ret)
			cout << "pthread_create error:error_code = " << ret << endl;
	}

	pthread_exit(NULL);
	return 0;
}
#else
void *print_hello(void *threadid)
{
	int tid = *(int *)threadid;
	cout << "hello  "<< "id:" << tid << endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threadids[NUM_THREADS];
	int indexes[NUM_THREADS];
	int rc,i;
	for(i=0;i<NUM_THREADS;i++){
		cout << "main():id="  << i << endl;
		indexes[i] = i;
		rc = pthread_create(&threadids[i],NULL,print_hello,(void *)&(indexes[i]));
		if(rc){
		cout << "error:" << rc << endl;
		exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}
#endif
