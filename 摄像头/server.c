
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
sem_t sem0,sem3;

static int pic_size=0;


char pic1[320*240];

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

	if( -1 == (fd = camera_init(devpath,&width,&height,&size,&ismjpeg)) )
	{
		printf("camera_init failed!\n");
		pthread_exit(NULL);
	}
	if( -1 == camera_start(fd) )
	{
		printf("camera_start failed!\n");
		camera_stop(fd);
		camera_exit(fd);
		pthread_exit(NULL);
	}
	printf("pthread_func\n");
	while(1)
	{
		printf("%s","A--START\n");
		memset(&index,0,sizeof(index));
		int a = 0;
		if( -1 ==(a= camera_dqbuf(fd,&buf,&pix_size,&index) ))
		{
			printf("%s","AAA--START\n");
			printf("camera_dqbuf failed!\n");
			camera_stop(fd);
			camera_exit(fd);
			break;
			printf("%s","AAA--end\n");
		}
		printf("a=%d\n",a);
		yuyv_2_rgb888(frame_buffer,width,height);
		printf("%s","start save\n");
		sleep(2);
		encode_jpeg(frame_buffer,width,height,JPEG);
		printf("%s"," save end \n");
		memset(pic1,0,sizeof(pic1));			
		pic_size=pix_size;
		sem_post(&sem0);
//		printf("line = %d\n",__LINE__);
		

	//	printf("line = %d\n",__LINE__);
		if( -1 == camera_eqbuf(fd,index) )
		{

			printf("camera_eqbuf failed!\n");
			camera_stop(fd);
			camera_exit(fd);
			break;

		}

		//	usleep(30);
	}
printf("%s","A--END\n");
}
void *write_func(void *arg)
{
	int ret;
	char buf_size[20] = {0};
	int sockfd = *((int*)arg);
	while(1)
	{
		printf("%s","B--START\n");
		printf("write_func\n");
		sem_wait(&sem0);
		sprintf(buf_size,"%d",pic_size);
		printf("buf_size:%d\n",pic_size);
		ret = write(sockfd,buf_size,sizeof(buf_size));
		if( 0 >= ret ) 
		{
			perror("write size");			
			break;
		}
		printf("size= %d\n",ret);

		int fp = open(JPEG,O_RDONLY);
			if(0 > fp){

				perror("open");
			}
                        int ret = 0;
			while(ret < pic_size){
				int a = read(fp,pic1,sizeof(pic1));
				printf("a=%d\n",a);
				int tmp = write(sockfd,pic1,a);
				ret += tmp;
				printf("tmp = %d\n",tmp);
				memset(pic1,0,sizeof(pic1));
				if(tmp <= 0){
					perror("write faile");
					break;
				}
			}

		printf("data= %d\n",ret);
		//usleep(30);
	}
	close(sockfd);
	free(arg);
	printf("sockfd close\n");
printf("%s","B--END\n");
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigaction( SIGPIPE, &sa, 0 );   //设置SIGPIPE信号处理方式为忽略
	
	if(sem_init(&sem0,0,0)<0)
	{
		perror("sem0 init");
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
	pthread_t pythread;
	if(pthread_create(&pythread,NULL,pthread_func,NULL) < 0)
	{
		perror("pthread create");
		return -2;
	}

	//usleep(30);

	int *p;
	pthread_t pthread;
	while(1)
	{
		printf("%s","C--START\n");
		memset(&cltaddr,0,sizeof(cltaddr));
		if( -1 == (sockfd = accept(listenfd,&cltaddr,&addrlen)))
		{
			perror("sockfd");
			continue;
		}
		p = (int *)malloc(sizeof(int));		//开辟空间装套接字，传递给线程
		*p = sockfd;
		if(pthread_create(&pthread,NULL,write_func,p) < 0)
		{
			perror("pthread create");
			free(p);
			continue;
		}
		printf("new connection....\n");
		pthread_detach(pthread);
	}
printf("%s","C--END\n");
	close(listenfd);
	printf("line = %d\n",__LINE__);
	return 0;
}

