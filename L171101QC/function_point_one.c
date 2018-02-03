#include <stdio.h>

typedef int  (*FUN)(int);//FUN是一个函数指针类型
/*
函数指针:指针,指向一个函数
指针函数:函数,其返回一个指针


定义函数指针:指针所指向的函数原型(函数三要素),由函数参数列返及回值确定
*/
//指针函数
int *  fun()
{
	static  int a;
	return &a;
}

int  fun2(int a)
{
	return a;
}

int  fun3(int b)
{
	return b+300;
}

int  fun4(int c)
{
	return 2;
}

int  fun5(int d)
{
	return 1;
}

//call back(回调函数定义与作用及执行机制)
//int   test(int a,int (*ptr2)(int))//函数指针作为另一个形参
int   test(int a,FUN ptr2 )
{
	printf("%d\n",ptr2(a));
}

int main(int argc, char const *argv[])
{
	//通过函数名 输出函数在代码端存储地址值
	// printf("%X\n",main);
	// printf("%X\n",fun);
	// //函数名表示函数起始地址
	// printf("%X\n",&main);
	// printf("%X\n",&fun);

   // char **  array[3][4];
   // printf("%d\n",sizeof(array));


	//定义函数指针
	//int  (*ptr)(int);
	//printf("%d\n",sizeof(ptr));
	//ptr=fun2;//函数指针赋值
	//printf("%d\n",ptr(200));//ptr(200) 调用函数  fun2(200)
	//ptr=fun;//错误, 指向同形式的函数

	//fun2=fun3;//函数名相当于 指针只读
	// ptr=fun2;
	// printf("%d\n",ptr(200));
	// ptr=fun3;
	// printf("%d\n",ptr(200));

	//定义函数指针数组
	//FUN    array[]={fun2,fun3};
	//int (*array[])(int)={fun2,fun3};
	// int (*array[2])(int);
	// array[0]=fun2;
	// array[1]=fun3;
	// printf("%d\n",array[0](200));
	// printf("%d\n",array[1](200));

	//定义指向函数指针数组的指针
	// FUN    array[]={fun2,fun3};
	// FUN *  ptr=array;
	// printf("%d\n",(*(ptr+0))(200));
	// printf("%d\n",(*(ptr+1))(200));

	//定义指向函数指针数组的数组指针
	// FUN    array[][2]={fun2,fun3,fun4,fun5};
	// //FUN    (*ptr)[2]=array;
	// int  (*(*ptr)[2])(int)=array;
	// printf("%d\n",ptr[0][0](100));
	// printf("%d\n",ptr[0][1](100));
	// printf("%d\n",ptr[1][0](100));
	// printf("%d\n",ptr[1][1](100));

	test(100,fun2);
	test(200,fun3);
	test(300,fun4);
	test(400,fun5);

	return 0;
}

//函数指针复杂形式分析:
/*
int *func(int a)
int  (*func)(int *p)
int  (*(*func)(int a,int b))(int a)
int  (*func)(int *p,int(*f)(int *))
int  (*func[5])(int *p)
int  (*(*func)[5])(int *p)
int  (*(*func)(int *p))[5]
*/
/*
int inc(int a)
{
return(++a);
}
int multi(int*a,int*b,int*c)
{
return(*c=*a**b);
}
typedef int(*FUNC1)(int in);
typedef int(*FUNC2) (int*,int*,int*);
void show(FUNC2 fun,int arg1, int*arg2)
{
FUNC1 p=&inc;
int temp =p(arg1);
fun(&temp,&arg1, arg2);
printf("%d\n",*arg2);
}
main()
{
int a;
show(multi,10,&a);
return 0;
}
*/