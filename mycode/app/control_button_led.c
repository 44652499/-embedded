#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <sys/ioctl.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <sys/select.h>
#include  <sys/time.h>
#include  <errno.h>
#define   FILE_RD_OPEN  O_RDONLY
/*
代码功能:通过按下开发板上第一个(k1)和第二个(k2)按键实现控制第一个led灯亮或灭
控制按键本质:读取按键设备映射文(linux 一切皆文件),/dev/buttons
控制LED本质:读取LED设备映射文,/dev/leds
文件操作步骤:
1.打开文件
2.读写文件
3.关闭文件
open
int open(const char *pathname, int flags);
const char *pathname:打开文件绝对或相对路径值
int flags:文件打开模式(只读O_WRONLY 只写O_RDONLY  读写 O_RDWR)
返回值: >0:打开文件描述值(系统分配无符号整数值>=3(为什么 不是从0开始?))
读文件
read
ssize_t read(int fd, void *buf, size_t count);
int fd:文件描述符,open返回值
void *buf:指向存放读取文件数据库空间
size_t count:空间最大存储字节数
返回值:>0 成功,实际读取的字节数
      -1:失败(errno获取失败原因)


[root@localhost ~]# man open
[root@localhost ~]# man 2 read  //2:表示linux系统库函数
*/
/*
系统错误信息输出函数
*/
void  system_error_out(const   char *  error_title)
{
	perror(error_title);
	exit(-1);
}
/*
控制LED等亮灭状态
int onoroff:灯亮或灭,1:亮  0:灭
int index:控制第几个LED灯索引(0 1 2 3)
*/
void  contorl_led_on_off(int onoroff,int index)
{
	int led_fd=open("/dev/leds",FILE_RD_OPEN);
	if(led_fd==-1)
	{
		system_error_out("contorl_led_on_off open:");
	}
	//设置led驱动参数值
    ioctl(led_fd,onoroff,index);
}
/*
检测按键函数
*/
void   check_button_click()
{
	//打开按键文件
	int  button_fd=open("/dev/buttons",FILE_RD_OPEN);
	if(button_fd==-1)
	{
		system_error_out("check_button_click open :");
	}
	//定义按键状态值存储数组,初始值为'0'
	char  buttons_value[8]={'0','0','0','0','0','0','0','0'};
	//轮询检测是否存在按键发生
	while(1)
	{
		//记录当前8个按键状态
		char  buttons_current_values[8];
		int read_bytes=read(button_fd,buttons_current_values,sizeof(buttons_current_values));
		if(read_bytes!=sizeof(buttons_current_values))
		{
			system_error_out("check_button_click read:");
		}
		int i;
		for(i=0;i<sizeof(buttons_value)/sizeof(buttons_value[i]);i++)
		{
			//比较当前按键值与初始值,判断是否存在按键动作发生
			if(buttons_value[i]!=buttons_current_values[i])
			{
				buttons_value[i]=buttons_current_values[i];
				//0:松开 弹起  1:按键
				if(buttons_value[i]==49)//49=='1'
				{
					//判断按键标志(k1)
					if(i+1==1)//第一个键被按下
					{
						//控制第一个LED灯亮
						contorl_led_on_off(1,0);
					}
					if(i+1==2)//第二个键被按下
					{
						//控制第一个LED灯灭
						contorl_led_on_off(0,0);
					}
				}
			}
		}
	}
	//关闭文件
	close(button_fd);
}
int main(int argc, char const *argv[])
{
	check_button_click();
	return 0;
}

/*
编译语句:
[root@localhost app]# gcc  control_button_led.c  -o  control_button   //编译生成执行文件为X86不能在开发板上执行


正确编译如下:
[root@localhost app]# arm-linux-gcc control_button_led.c  -o  control_button
[root@localhost app]# file control_button

*/