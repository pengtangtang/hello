
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <fcntl.h>

#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<netinet/ip.h>

#include<arpa/inet.h>

#include <pthread.h>
#include <semaphore.h>
#include "jpeglib.h"


#define devpath "/dev/video0"
#define IMAGEWIDTH 320
#define IMAGEHEIGHT 240
#define JPEG "camera.jpg"

unsigned char frame_buffer[IMAGEWIDTH*IMAGEHEIGHT*3];
pthread_mutex_t mutex;
//static int pic_size=0;
char pic1[1024*1024];
char buf_size[20] = {0};

void *pthread_func(void *arg)
{
	unsigned int width = 320;
	unsigned int height = 240;
	unsigned int size;
	unsigned int ismjpeg;

	int pix_size;

	unsigned int index;
	int i;

	int fd;
	void *buf;

	if( -1 == (fd = camera_init(devpath,&width,&height,&size,&ismjpeg)))
	{
		pthread_exit(NULL);
	}
	if( -1 == camera_start(fd) )
	{
		camera_stop(fd);
		camera_exit(fd);
		pthread_exit(NULL);
	}
	printf("pthread_func\n");
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if( -1 == camera_dqbuf(fd,&buf,&pix_size,&index) )
		{
			printf("camera_dqbuf failed!\n");
			camera_stop(fd);
			camera_exit(fd);
			break;
		}
		yuyv_2_rgb888(frame_buffer,width,height);
		encode_jpeg(frame_buffer,width,height,pic1);
		//pic_size=pix_size;
		sleep(2);
		sprintf(buf_size,"%d",pix_size);
		printf("pix_size=%d\n",pix_size);
		pthread_mutex_unlock(&mutex);
		if( -1 == camera_eqbuf(fd,index) )
		{

			printf("camera_eqbuf failed!\n");
			camera_stop(fd);
			camera_exit(fd);
			break;

		}
		pix_size = 0;

	}
}
void *write_func(void *arg)
{
	int ret;
	int sockfd = *((int*)arg);
	while(1)
	{
		printf("write_func\n");

		pthread_mutex_lock(&mutex);
		ret = write(sockfd,buf_size,sizeof(buf_size));
		printf("ret=%d\n",ret);
		if( 0 >= ret ) 
		{
			  perror("write size");			
			  break;
		}
		ret = write(sockfd,pic1,sizeof(pic1));
		printf("ret1=%d\n",ret);
		if( 0 >= ret ) 
		{
			  perror("write size");			
			  break;
		}
		pthread_mutex_unlock(&mutex);
	}
	close(sockfd);
	free(arg);
	printf("sockfd close\n");
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigaction( SIGPIPE, &sa, 0 );   //设置SIGPIPE信号处理方式为忽略

	if(pthread_mutex_init(&mutex,NULL) < 0)
	{
		perror("pthread_mutex_init");
		return -1;
	}

	int listenfd;
	if( -1 == (listenfd = socket(AF_INET,SOCK_STREAM,0)) )
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in sevaddr;
	memset(&sevaddr,0,sizeof(sevaddr));
	sevaddr.sin_family = AF_INET;
	sevaddr.sin_port = htons(8888);
	sevaddr.sin_addr.s_addr = htonl(INADDR_ANY);


	int val = 1;
	if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&val,sizeof(&val)) == -1)
	{
		perror("setsockopt");
	}

	if( -1 == bind(listenfd,(const struct sockaddr *)&sevaddr,sizeof(sevaddr)) )
	{
		perror("bind");
		exit(-1);
	}

	if( -1 == listen(listenfd,10) )
	{
		perror("listen");
		exit(-1);
	}
	int sockfd;
	pid_t pid;
	struct sockaddr cltaddr;
	socklen_t addrlen = sizeof(cltaddr);

	int *p;
	pthread_t pthread;
	while(1)
	{
		memset(&cltaddr,0,sizeof(cltaddr));
		if( -1 == (sockfd = accept(listenfd,&cltaddr,&addrlen)))
		{
			perror("sockfd");
			continue;
		}

		pthread_t pythread;/*视频采集*/
		if(pthread_create(&pythread,NULL,pthread_func,NULL) < 0)
		{
			perror("pthread create");
			return -2;
		}

		p = (int *)malloc(sizeof(int));		//开辟空间装套接字，传递给线程
		*p = sockfd;/*视频发送*/
		if(pthread_create(&pthread,NULL,write_func,p) < 0)
		{
			perror("pthread create");
			free(p);
			continue;
		}
		printf("new connection....\n");
		pthread_detach(pthread);
	}
	close(listenfd);
	return 0;
}

