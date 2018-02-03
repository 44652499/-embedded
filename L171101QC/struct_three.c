#include <stdio.h>
// typedef struct 
// {
// 	int a;
// 	--int b;
// }A;

typedef struct 
{
}A;

int main(int argc, char const *argv[])
{
	//A obj={2};//局部初始化结构成员值,剩下的成员值为0.等同于数组初始化
	//printf("%d\n",obj.a/obj.b);//  2/0

	// A  obj={10,20};
	// int * ptr=(int*)&obj;
	// printf("%d\n",ptr[0]);//*(ptr+0)
	// printf("%d\n",ptr[1]);//*(ptr+1);
    int  a[0];
    printf("%d\n",sizeof(a));
    A obj;
	printf("%d\n",sizeof(A));//c标准当作0字节,c++标准算1个字节
	return 0;
}