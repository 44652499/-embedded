#include <stdio.h>
/*
变量存储类型:
a.auto:默认存储类型,一般表示局部变量存储类型
b.register:存储在寄存器
c.static
d.extern:文件外部引用,一个文件使用另一个文件全局变量
e.volatile(一般不认为是存储类型)

static全局变量与一般全局变量区别:
1.static 全局变量只能在本文件内使用,不能跨文件
static局部变量与一般局部变量区别:
1.存储位置不同,系统给予初始值不同
2.静态局部变量只初始化一次.在进程结束时释放

volatile:每次从变量空间中获取最新的值.
volatile int i=20;
int k=i;
int a=k;
volatile  取消编译器优化,获取最新的值
*/
//auto int g_data;//错误
static int s_data;//静态未初始化全局变量

int  fun(int a)
{
    //int sum=0;//一般局部变量,每次都会分配释放,初始化位0
    static int sum=0;//静态局部变量,只会分配一次,只会初始化一次
    //第一个初始化,后续都使用上一次值
	sum=sum+a;
	return sum;
}

int main(int argc, char const *argv[])
{

    int i;
	int s=0;
	for(i=0;i<5;i++)
	{
      s=s+fun(i);
	}
	printf("%d\n",s);

	//auto int a;//int a;
	//register int r_a=20;
	//printf("%X\n",&r_a);//错误,寄存器变量没有地址
	//static  int s_data2;//静态为初始化局部变量
	//printf("%x\t%X\n",&s_data,&s_data2);
	//printf("%d\n",s_data2);
	// {
	// 	static  int s_data2=30;
	// 	printf("%d\n",s_data2);
	// }
	//printf("%d\n",s_data2);//错误,只能本作用域内访问
	return 0;
}