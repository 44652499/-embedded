#include <stdio.h>
/*
typedef 通常被用于以下三种目的
1.定义一种类型的别名,而不只是简单的宏替换
2.简化复杂的类型定义,使其更易理解
3.用typedef来定义与平台无关的类型


陷阱一:
typedef是定义了一种类型的新别名,不同于宏,它不是简单的字符串替换
typedef string *pstring;
const pstring cstr
陷阱二:
typedef在语法上是一个存储类的关键字(如auto、extern、mutable、static、register等一样),
虽然它并不真正影响对象的存储特性,如：
typedef static int INT2; //不可行 报声明指定了多个存储类错误

typedef与define区别:
1.#define是预处理指令,在编译预处理时进行简单的替换,不作正确性检查
2.typedef是在编译时处理的.它在自己的作用域内给一个已经存在的类型一个别名

define 与const区别:
1.编译器处理方式不同
　　define宏是在预处理阶段展开
　　const常量是编译运行阶段使用
2.类型和安全检查不同
　　define宏没有类型,不做任何类型检查,仅仅是展开
　　const常量有具体的类型,在编译阶段会执行类型检查
3.存储方式不同
　　define宏仅仅是展开,有多少地方使用,就展开多少次,不会分配内存。
　　const常量会在内存中分配(可以是堆中也可以是栈中)
4.const可以节省空间,避免不必要的内存分配
  const定义常量从汇编的角度来看,只是给出了对应的内存地址,
  而不是象#define一样给出的是立即数,所以,const定义的常量
  在程序运行过程中只有一份拷贝,而#define定义的常量在内存
  中有若干个拷贝 
*/
//typedef string *pstring;
//typedef static int INT2;
typedef  int * A;
typedef  int B[4];
typedef  int C[3][4];
int main(int argc, char const *argv[])
{
	//const pstring cstr;//错误的认为是const string * cstr,正确是string *const cstr;
	//char* pa, pb; // 只声明了一个指向字符变量的指针
	//以下则可行：
    //typedef char* PCHAR; // 一般用大写
    //PCHAR pa, pb; //同时声明了两个指向字符变量的指针
    int data=200;
	A p1=&data;
	printf("%d\n",*p1);
	B  array1;
	int i;
	for(i=0;i<4;i++)
	{
		array1[i]=i+1;
	}
	for(i=0;i<4;i++)
	{
		printf("%d\t",array1[i]);
	}
	printf("\n");
	C  array2;
	int j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			array2[i][j]=i+j;
			printf("%d\t",array2[i][j]);
		}
		printf("\n");
	}
	return 0;
}