#include  <stdio.h>
/*
写：从用户控件缓存区复制数据到系统内核空间，程序写入数据到用户空间缓存
写数据可能发生堵塞：
1.内核空间缓存写满
2.用户空间缓存数据多余内核缓存剩余空间
3.内核空间发生写入错误（异常）

读：从 内核读缓存区 
复制数据到用户空间缓存，进程是从用户空间缓存获取数据
读操作堵塞情况：
1.内核缓存为空
2.用户缓存满
3.内核空间发生读错误（异常）

I/O操作几种模型:
1.堵塞：read /recv /recvfrom  write/send/sendto
2.非堵塞：改变文件描述状态标志（O_NONBLOCK），一般返回错误编号： EAGAIN  或 EWOULDBLOCK
3.信号驱动SIGIO：信号软中断实现
4.异步aio操作：异步操作 aio_read  aio_write aio_error   aio_listio  aio_return aio_calcel aio_suspend ,struct  aiocb
5.IO多路复用（select  epoll） :内核监控多个文件描述符，复制即将可读可写的文件描述符到用户空间，用户空间收到文件描述符后非堵塞。select  epoll都是堵塞性函数
*/
int main(int argc, char const *argv[])
{
	
	return 0;
}