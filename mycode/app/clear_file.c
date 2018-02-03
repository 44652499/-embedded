#include "define_all_header.h"
int main(int argc, char const *argv[])
{
	int fd=open("abc.txt",O_WRONLY|O_CREAT|O_EXCL,0777);
	if(fd>0)
	{
		write(fd,"14123123123213213",strlen("14123123123213213"));
	}
	close(fd);
	unlink("abc.txt");
	fd=open("abc.txt",O_WRONLY|O_CREAT|O_EXCL,0777);
	if(fd>0)
	{
		write(fd,"12321asdad",strlen("12321asdad"));
	}
	else
	{
		perror("open:");
	}
	close(fd);
	// fd=open("abc.txt",O_WRONLY|O_TRUNC);
	// if(fd>0)
	// {
	// 	write(fd,"hellohello",strlen("hellohello"));
	// }
	// close(fd);
	return 0;
}