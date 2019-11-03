/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pthread_join.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#define NUM_THREADS 5

void *wait(void *t)
{
	int i;
	long tid;

	tid = (long)t;

	sleep(1);
	cout << "sleep in thread \n";
	cout << "thread with id : " << tid << "..exiting\n";
	pthread_exit(NULL);
}

int main()
{
	int rc,i;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	for(i=0;i<NUM_THREADS;i++){
		cout << "main():creating thread," << i << endl;
		rc = pthread_create(&threads[i],NULL,wait,(void *)i);

		if(rc){
			cout << "error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);
	for(i=0;i<NUM_THREADS;i++){
		rc = pthread_join(threads[i],&status);
		if(rc){
			cout << "error:unable to join," << rc << endl;
			exit(-1);
		}
		cout << "main:program exiting." << endl;
		pthread_exit(NULL);
	}
}

