/*
author:jon lee
date:2016-3-21
description:在开发板端实现摄像头的图像抓取,生成一个AVI文件,发送给客户端
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <linux/videodev2.h>
#include <asm/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include "avi.h"
#include "simplified_jpeg_encoder.h"

#define LISTENPORT 6789
#define LISTENADDRIP "192.168.252.5"
#define LISTENNUM 20
#define DEVICE_NAME "/dev/video0"

typedef struct videobuffer
{
		void *start;
		size_t length;
}videobuffer;

typedef struct buf_t
{
		unsigned int datasize;
		char buf[];
}buf_t;

buf_t *g_bufpoint;
videobuffer *gs_buffers=NULL;
pthread_mutex_t g_lock;
pthread_cond_t g_cond;
int g_device_fd;
FILE* g_avi;
struct v4l2_format g_v412_fmt;

/*
function:输出系统错误信息
parameters:
          char * errmsg   指向错误消息数据指针
*/
void  output_sys_errmsg(char * errmsg)
{
	perror(errmsg);
}

/*
function:打开摄像头设备
return value:成功打开设备文件描述符纸
             -1:失败
*/
unsigned int  open_device()
{
	int device_fd=-1;
	device_fd=open(DEVICE_NAME,O_RDWR);
	if(device_fd==-1)
	{
		output_sys_errmsg("open_device-open:");
		exit(-1);
	}
	return device_fd;
}

/*
function:创建套接字,初始化监听地址结构,绑定 监听
return value: 成功 监听套接字
              失败  -1
*/
unsigned int init_listent_sock()
{
	unsigned int listentsock=-1;
	listentsock=socket(AF_INET,SOCK_STREAM,0);
	if(listentsock==-1)
	{
       output_sys_errmsg("init_listent_sock-socket:");
       exit(-1);
	}
	struct sockaddr_in server_addr;
	socklen_t addrlen=sizeof(server_addr);
	bzero(&server_addr,addrlen);
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(LISTENPORT);
	server_addr.sin_addr.s_addr=inet_ntoa(LISTENADDRIP);
	int ret=bind(listentsock,(struct sockaddr*)&server_addr,addrlen);
	if(ret==-1)
	{
	   output_sys_errmsg("init_listent_sock-bind:");
       exit(-1);
	}
	ret=listen(listentsock,LISTENNUM);
	if(ret==-1)
	{
		output_sys_errmsg("init_listent_sock-listen:");
	}
	return listentsock;
} 

/*
function:设置视频格式
*/
void  set_video_format()
{
	//struct v4l2_capability  v412_cap;//获取视频设备的功能
	memset(&g_v412_fmt,0,sizeof(g_v412_fmt));
	g_v412_fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;//数据流类型
	g_v412_fmt.fmt.pix.width=320;//宽，必须是16的倍数
	g_v412_fmt.fmt.pix.height=240;//高，必须是16的倍数
	g_v412_fmt.fmt.pix.pixelformat=V4L2_PIX_FMT_YUYV;// 视频数据存储类型
	if(ioctl(g_device_fd,VIDIOC_S_FMT,&g_v412_fmt)<0)
	{
		output_sys_errmsg("set_video_format-ioctl-VIDIOC_S_FMT:");
		exit(-1);
	}
	if(V4L2_PIX_FMT_YVU420 ==g_v412_fmt.fmt.pix.pixelformat)
    {
        printf("support FMT_YVU420\n");
    }
    else if(V4L2_PIX_FMT_JPEG ==g_v412_fmt.fmt.pix.pixelformat)
    {
        printf("support FMT_JPEG\n");
    }
    else if(V4L2_PIX_FMT_RGB24 == g_v412_fmt.fmt.pix.pixelformat)
    {
        printf("support FMT_RGB24\n");
    }
    else if(V4L2_PIX_FMT_YUYV == g_v412_fmt.fmt.pix.pixelformat)
    {
        printf("support FMT_YUYV\n");
    }
    else if(V4L2_PIX_FMT_MJPEG == g_v412_fmt.fmt.pix.pixelformat)
    {
        printf("support FMT_MJPEG\n");
    }
}
/*
function:设置分配本地内存
*/
void  set_local_mem()
{
    int bufcnt=0;
	struct v4l2_requestbuffers  request_buf;
	struct v4l2_buffer v412_buf;
	gs_buffers=(videobuffer*)malloc(request_buf.count*sizeof(videobuffer));
	if(gs_buffers==NULL)
	{
		output_sys_errmsg("set_local_mem-malloc:");
		exit(-1);
	}
	request_buf.count=4;
	request_buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	request_buf.memory=V4L2_MEMORY_MMAP;

	if(ioctl(g_device_fd,VIDIOC_REQBUFS, &request_buf) == -1) 
	{
		output_sys_errmsg("set_local_mem-ioctl-VIDIOC_REQBUFS:");
	    exit(-1);
	}
	for(bufcnt=0;bufcnt<request_buf.count;bufcnt++)
	{
        memset(&v412_buf,0,sizeof(v412_buf));
        v412_buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		v412_buf.memory = V4L2_MEMORY_MMAP;
		v412_buf.index = bufcnt;

		if(ioctl(g_device_fd, VIDIOC_QUERYBUF, &gs_buffers) == -1)//读取缓存信息 
		{
			output_sys_errmsg("set_local_mem-ioctl-VIDIOC_QUERYBUF:");
			exit(-1);
	    }
				
		buffers[bufcnt].length=request_buf.length;
		buffers[bufcnt].start=mmap(NULL,request_buf.length,
								PROT_READ | PROT_WRITE,
								MAP_SHARED,fd, request_buf.m.offset);//转换成相对地址
		if(buffers[bufcnt].start==MAP_FAILED)
		{
			return -1;
		}
		if(ioctl(fd,VIDIOC_QBUF,&buf)==-1)//放入缓存队列
		{
			return -1;
		}
	}
}
/*
function:线程执行函数,开始录制视屏
*/
void*  video_on(void* arg)
{
	return NULL;
}


/*
function:线程执行函数,开始发送视屏
*/
void* video_send(void* arg)
{
	return NULL;
}
/*
function:创建线程实现视屏文件的创建,及其发送
parameter:
          unsigned int listen_sock  监听套接字 
*/
void  video_work(unsigned int listen_sock)
{
	pthread_t pthreadid;	
	fd_set red_set;
	int max_sock=listen_sock;
	struct timeval tv;
	pthread_mutex_init(&g_lock,NULL);
	pthread_cond_init(&g_cond,NULL);
	int ret=pthread_create(&pthreadid,NULL,video_on,NULL);
	while(ret==-1)
	{
		ret=pthread_create(&pthreadid,NULL,video_on,NULL);
	}
	while(1)
	{
		FD_ZERO(&red_set);
		FD_SET(listen_sock,&red_set);
		tv.tv_sec=30;
		tv.tv_usec=0;
		ret=select(max_sock+1,&red_set,NULL,NULL,NULL);
		if(ret<0)
		{
			output_sys_errmsg("video_work-select:");
			break;
		}
		if(ret==0)
		{
			output_sys_errmsg("video_work-select:timeout");
			continue;
		}
		if(FD_ISSET(listen_sock,&red_set))
		{
			ret=pthread_create(&pthreadid,NULL,video_send,NULL);
		}
	}
}

int main(int argc, char const *argv[])
{
	g_device_fd=open_device();
	return 0;
}