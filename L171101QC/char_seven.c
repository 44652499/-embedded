#include <stdio.h>
#include <string.h>
/*
二级指针:指向指针的指针
1.首先是一个指针变量,占用4字节
2.指针变量存储的值是另一个空间的地址值,另一个空间必须是一个指针变量
*/

// void  fun(char * p)//p为空
// {
// 	char ch[20];
// 	p=ch;//p指向ch
// }
//更正一
// char*  fun(char * p)//p为空
// {
// 	//char ch[20];//fun 调用结束,释放栈
// 	static char ch[20];
// 	p=ch;//p指向ch
// 	return  p;
// }
//更正
// void  fun(char ** p)
// {
// 	static char ch[20];
// 	*p=ch;//p指向ch
// }
int main(int argc, char const *argv[])
{
	char  * str=NULL;
	//fun(str);

	//str=fun(str);

	// fun(&str);
	// strcpy(str,"hello");//str 仍然为空
	// printf("%s\n",str);
	
	// int a=20;
	// int *  ptr1=&a;
	// int ** ptr2=&ptr1;//记录ptr1空间的地址
	// printf("%d\n",**ptr2);

	// char **ch;
	// printf("%d\n",sizeof(ch));//一级指针地址
	// printf("%d\n",sizeof(&ch));//二级指针地址
	// printf("%d\n",sizeof(*ch));//一级指针存放值
	// printf("%d\n",sizeof(**ch));//存储字符类型值

    // int a=300;
    // int  **ptr=(int**)&a;
    // printf("%d\n",*(int*)ptr);//二级指针弱化成一级指针

    int  array[][3]={1,2,3,4,5,6};
    //int **ptr=(int**)array;
    //int **ptr=&array[0][0];//错误
    char ** ptr=(char**)array;
    int i,j;
    for(i=0;i<2;i++)
    {
    	for(j=0;j<3;j++)
    	{
    		//printf("%d\n",ptr[i][j]);
    		//printf("%d\n",*((int*)(ptr+i*3)+j));

    		printf("%d\n",*((int*)((char*)ptr+i*3*sizeof(int))+j));
    		//printf("%d\n",*((int*)(ptr+i*3*sizeof(int))+j));///错误
            //ptr  是一个二级指针,ptr+1 增加的时4个字节为一空间.
            //i*3*sizeof(int) 计算的时字节数,非空间数
    	}
    	printf("\n");
    }
	return 0;
}