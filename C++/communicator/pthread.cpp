/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pthread.cpp
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
#define NUM_THREADS 5

struct thread_data{
	int thread_id;
	char *message;
};

void *print_hello(void *threadarg)
{
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;

	cout << "thread id : " << my_data->thread_id << endl;	
	cout << "message: " << my_data->message << endl;

	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	int rc,i;

	for(i=0;i<NUM_THREADS;i++){
		cout << "main():creating thread," << i << endl;
		td[i].thread_id = i;
		td[i].message = "this is message";

		rc = pthread_create(&threads[i],NULL,print_hello,(void *)&td[i]);

		if(rc){
			cout << "error :unable to create thread, " << rc << endl;
			exit(-1);
		}
	}

	pthread_exit(NULL);
	return 0;
}
