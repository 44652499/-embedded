#include <stdio.h>
#include <limits.h>
/*
c语言常用的符号:
1.运算符号: +  -  *  /  %
2.比较符号: > >= < <=  == !=
3.逻辑符号: &&   ||  !
4.位运算符号:&  |  ~ ^ <<  >>
5.?:
6.赋值:=   +=  -=  *=
7. , () ++  +  -  --  ()  []  ->  . 等
*/

int c;
int main(int argc, char const *argv[])
{
	//int a=5;
	//unsigned int b=20;
	//printf("%d\n",a-b);	//%d有符号数a-b是一个无符号数,输出是内部作了转换%u--->%d
	//printf("%c\n",a>b?'y':'n');//if(a>b) 'y' else 'n'
    /*有符号与无符号运算其结果必定是无符号数*/
	//printf("%c\n",a-b>0?'y':'n');
	//printf("%u\n",a-b);//%u表示无符号数

    //不能使用比较符号,判断任意整数a,b 大小?
    // int i_a;
    // int  i_b;
    // scanf("%d%d",&i_a,&i_b); 
    // //printf("%c\n",10%3?'y':'n');
    // printf("%d\n",abs(i_a-i_b)-(i_a-i_b)?i_b:i_a);

    //c语言用0表示假,非0(+1,-1)表示真   
   //  int c;   
   // // c=0;
   //  if(c)//访问同一个作用域的c,全局c访问不到
   //  {
   //  	  printf("ok\n");
   //  }
   //  else
   //  {
   //  	  printf("no\n");
   //  }

	//不使用第三个变量实现 a,b值交换
	//int  i_a=5;
	//int  i_b=6;
	//i_a=i_a+i_b;//存在bug,i_a+i_b计算结果超出最大值
	//i_b=i_a-i_b;
	//i_a=i_a-i_b;
   // printf("%d\t%d\n",i_a,i_b);

	//int i_a=INT_MAX;
	//int i_b=INT_MAX;
	//i_a=i_a+i_b;
	//printf("%d\n",i_a);//错误


	int i_a=512;
	//int i_b=256;
    int i_b=1024;
    char c;
    c=i_a;//溢出
    i_a=i_b;
    i_b=c;
    printf("%d\t%d\n",i_a,i_b);	
	return 0;
}