#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "jpeglib.h"
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <linux/videodev2.h>

#define  IMAGEWIDTH    320
#define  IMAGEHEIGHT   480
#define	REQBUFS_COUNT	4
#define TRUE 1
#define FALSE 0

typedef int BOOL;


struct cam_buf {
	void *start;
	size_t length;
} * buffers;

struct v4l2_requestbuffers reqbufs;
struct cam_buf bufs[REQBUFS_COUNT];

unsigned char frame_buffer[IMAGEWIDTH*IMAGEHEIGHT*3];
int camera_init(char *devpath, unsigned int *width, unsigned int *height, unsigned int *size, unsigned int *ismjpeg)
{
	int i;
	int fd;
	int ret;
	struct v4l2_buffer vbuf;
	struct v4l2_format format;
	struct v4l2_capability capability;

	fd = open(devpath, O_RDWR);//打开摄像头
	if (fd == -1) {
		perror("camera->init");
		return -1;
	}

	ret = ioctl(fd, VIDIOC_QUERYCAP, &capability);//查询设备属性
	if (ret == -1) {
		perror("camera->init");
		return -1;
	}
	//判断设备是否支持v4l2__
	if(!(capability.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
		fprintf(stderr, "camera->init: device can not support V4L2_CAP_VIDEO_CAPTURE\n");
		close(fd);
		return -1;
	}
	//判断设备是否支持...
	if(!(capability.capabilities & V4L2_CAP_STREAMING)) {
		fprintf(stderr, "camera->init: device can not support V4L2_CAP_STREAMING\n");
		close(fd);
		return -1;
	}
	
	//设置数据/设备格式
	memset(&format, 0, sizeof(format));
	format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
	format.fmt.pix.width = *width;
	format.fmt.pix.height = *height;
	format.fmt.pix.field = V4L2_FIELD_ANY;
	ret = ioctl(fd, VIDIOC_S_FMT, &format);
	if(ret == -1)
		perror("camera init");
	else {
		fprintf(stdout, "camera->init: picture format is mjpeg\n");
		*ismjpeg = 1;
		goto get_fmt;
	}

	memset(&format, 0, sizeof(format));
	format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
	format.fmt.pix.width = *width;
	format.fmt.pix.height = *height;
	format.fmt.pix.field = V4L2_FIELD_ANY;
	ret = ioctl(fd, VIDIOC_S_FMT, &format);
	if(ret == -1) {
		perror("camera init");
		return -1;
	} else {
		*ismjpeg = 0;
		fprintf(stdout, "camera->init: picture format is yuyv\n");
	}

get_fmt:
	ret = ioctl(fd, VIDIOC_G_FMT, &format);
	if (ret == -1) {
		perror("camera init");
		return -1;
	}
//申请缓冲区
	memset(&reqbufs, 0, sizeof(struct v4l2_requestbuffers));
	reqbufs.count	= REQBUFS_COUNT;
	reqbufs.type	= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	reqbufs.memory	= V4L2_MEMORY_MMAP;
	ret = ioctl(fd, VIDIOC_REQBUFS, &reqbufs);	
	if (ret == -1) {	
		perror("camera init");
		close(fd);
		return -1;
	}
//设置缓冲区
	for (i = 0; i < reqbufs.count; i++)
	{
		memset(&vbuf, 0, sizeof(struct v4l2_buffer));
		vbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		vbuf.memory = V4L2_MEMORY_MMAP;
		vbuf.index = i;
		ret = ioctl(fd, VIDIOC_QUERYBUF, &vbuf);
		if (ret == -1) {
			perror("camera init");
			close(fd);
			return -1;
		}
//内存映射
		bufs[i].length = vbuf.length;
		bufs[i].start = mmap(NULL, vbuf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, vbuf.m.offset);
		if (bufs[i].start == MAP_FAILED)
		{
			perror("camera init");
			close(fd);
			return -1;
		}
//将缓冲帧入队列
		vbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		vbuf.memory = V4L2_MEMORY_MMAP;
		ret = ioctl(fd, VIDIOC_QBUF, &vbuf);
		if (ret == -1) {
			perror("camera init");
			close(fd);
			return -1;
		}
	}

	*width = format.fmt.pix.width;
	*height = format.fmt.pix.height;
	*size = bufs[0].length;

	return fd;
}

int camera_start(int fd)
{
	int ret;
	enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	ret = ioctl(fd, VIDIOC_STREAMON, &type);
	if (ret == -1) {
		perror("camera->start");
		return -1;
	}
	fprintf(stdout, "camera->start: start capture\n");

	return 0;
}

int camera_dqbuf(int fd, void **buf, unsigned int *size, unsigned int *index)
{
	int ret;
	fd_set fds;
	struct timeval timeout;
	struct v4l2_buffer vbuf;

	while (1) {
		FD_ZERO(&fds);
		FD_SET(fd, &fds);
		timeout.tv_sec = 2;
		timeout.tv_usec = 0;
		//将缓冲帧出队
			vbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
			vbuf.memory = V4L2_MEMORY_MMAP;
			ret = ioctl(fd, VIDIOC_DQBUF, &vbuf);
			if (ret == -1) {
				perror("camera->dqbuf");
				return -1;
			}
			*buf = bufs[vbuf.index].start;
			*size = vbuf.bytesused;
			*index = vbuf.index;

			return 0;
	//	}
	}
}

int camera_eqbuf(int fd, unsigned int index)
{
	int ret;
	struct v4l2_buffer vbuf;
//将处理完的一帧放回队列
	vbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	vbuf.memory = V4L2_MEMORY_MMAP;
	vbuf.index = index;
	ret = ioctl(fd, VIDIOC_QBUF, &vbuf);
	if (ret == -1) {
		perror("camera->eqbuf");
		return -1;
	}

	return 0;
}
int yuyv_2_rgb888(char *frame_buffer,int width,int height)
{
	int           i,j;
	unsigned char y1,y2,u,v;
	int r1,g1,b1,r2,g2,b2;
	char * pointer;

	pointer = bufs[0].start;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width/2;j++)//每次取4个字节，也就是两个像素点，转换rgb，6个字节，还是两个像素点
		{
			y1 = *( pointer + (i*width/2+j)*4);     
			u  = *( pointer + (i*width/2+j)*4 + 1);
			y2 = *( pointer + (i*width/2+j)*4 + 2);
			v  = *( pointer + (i*width/2+j)*4 + 3);

			r1 = y1 + 1.042*(v-128);
			g1 = y1 - 0.34414*(u-128) - 0.71414*(v-128);
			b1 = y1 + 1.772*(u-128);

			r2 = y2 + 1.042*(v-128);
			g2 = y2 - 0.34414*(u-128) - 0.71414*(v-128);
			b2 = y2 + 1.772*(u-128);

			if(r1>255)
				r1 = 255;
			else if(r1<0)
				r1 = 0;

			if(b1>255)
				b1 = 255;
			else if(b1<0)
				b1 = 0;    

			if(g1>255)
				g1 = 255;
			else if(g1<0)
				g1 = 0;    

			if(r2>255)
				r2 = 255;
			else if(r2<0)
				r2 = 0;

			if(b2>255)
				b2 = 255;
			else if(b2<0)
				b2 = 0;    

			if(g2>255)
				g2 = 255;
			else if(g2<0)
				g2 = 0;        

			*(frame_buffer + (i*width/2+j)*6    ) = (unsigned char)b1;
			*(frame_buffer + (i*width/2+j)*6 + 1) = (unsigned char)g1;
			*(frame_buffer + (i*width/2+j)*6 + 2) = (unsigned char)r1;
			*(frame_buffer + (i*width/2+j)*6 + 3) = (unsigned char)b2;
			*(frame_buffer + (i*width/2+j)*6 + 4) = (unsigned char)g2;
			*(frame_buffer + (i*width/2+j)*6 + 5) = (unsigned char)r2;
		}
	}
//	printf("change to RGB OK \n");
}

//图片压缩为jpeg格式
BOOL encode_jpeg(char *lpbuf,int width,int height,char *JPEG)
{/*初始化jpeg*/
	struct jpeg_compress_struct cinfo ;//定义一个压缩对象，这个对象主要用于处理主要的功能
	struct jpeg_error_mgr jerr ;//用于错误信息
	JSAMPROW  row_pointer[1] ;
	int row_stride ;
	char *buf=NULL ;
	int x ;
	FILE *fptr_jpg = fopen(JPEG,"wb");//定义压缩后的输出，这里输出到一个文件
	if(fptr_jpg==NULL)
	{
		printf("Encoder:open file failed!/n") ;
		return FALSE;
	}

	cinfo.err = jpeg_std_error(&jerr);//初始化错误信息，错误输出绑定
	jpeg_create_compress(&cinfo);//初始化压缩对象
	jpeg_stdio_dest(&cinfo, fptr_jpg);//绑定输出
//压缩参数设置
	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;
//参数设置为默认参数
	jpeg_set_defaults(&cinfo);

//设定编码jpeg压缩质量
	jpeg_set_quality(&cinfo, 80,TRUE);

//开始压缩，执行这一行数据后，无法在设置参数
	jpeg_start_compress(&cinfo, TRUE);

	row_stride = width * 3;
	buf=malloc(row_stride) ;
	row_pointer[0] = buf;
	while (cinfo.next_scanline < height)
	{//一行一行压缩
		for (x = 0; x < row_stride; x+=3)
		{

			buf[x]   = lpbuf[x];
			buf[x+1] = lpbuf[x+1];
			buf[x+2] = lpbuf[x+2];

		}
		jpeg_write_scanlines (&cinfo, row_pointer, 1);//critical
		lpbuf += row_stride;
	}

	jpeg_finish_compress(&cinfo);
	fclose(fptr_jpg);
	jpeg_destroy_compress(&cinfo);//清空对象
	free(buf) ;

	return TRUE ;
}  

int camera_stop(int fd)
{
	int ret;
	enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	ret = ioctl(fd, VIDIOC_STREAMOFF, &type);
	if (ret == -1) {
		perror("camera->stop");
		return -1;
	}
	fprintf(stdout, "camera->stop: stop capture\n");

	return 0;
}

int camera_exit(int fd)
{
	int i;
	int ret;
	struct v4l2_buffer vbuf;

	vbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	vbuf.memory = V4L2_MEMORY_MMAP;

	for (i = 0; i < reqbufs.count; i++) {
		ret = ioctl(fd, VIDIOC_DQBUF, &vbuf);
		if (ret == -1)
			break;
	}

	for (i = 0; i < reqbufs.count; i++)
		munmap(bufs[i].start, bufs[i].length);

	fprintf(stdout, "camera->exit: camera exit\n");

	return close(fd);
}
