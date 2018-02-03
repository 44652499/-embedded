#include <stdio.h>
/*
i++:先赋值再加1,首先创建一个临时变量将i值赋给临时变量,再i+1
++i:先加1再赋值,不存在临时变量,使用i空间完成运算
++i效率高于i++

贪心法:多个符号连续出现时,首先取出第一个符号,如果后面继续是符号.把连个符号合成一起如果合成之后也是一个正确符号,否则不能合成


*/
int main(int argc, char const *argv[])
{
	
	//int a=5;
	//int b=a++;
	//int b=a+++a;//a++ 后置在表达式计算结束后在加1
	//printf("%d\t%d\n",a,b);

	//int i=3;
	//printf("%d\n",(i++)+(i++)+(i++));//结果为9 ,
	//printf("%d\n",(++i)+(++i)+(++i));
	//int a=3;
	//printf("%d\n",a+++++a);
	//贪心法:a++ ++  +a:
	//a++ a=a+1   4++  相当于 4=4+1
	//使用空格断开
	//printf("%d\n",a++ + ++a);
	//printf("%d\n",(a++) + (++a));

	//int *p;
	//int c=20/*p;// /*注释一部分
	//int c=20/ *p;

	int a=4;
	//printf("%d\t%d\t%d\n",a,++a,a++);
	//printf("%d\t%d\t%d\n",a,a++,++a);
	//a+=a++;//a=a+a++
	//printf("a=%d\n",a);
	//a+=++a;//a=a+ ++a;
	//printf("a=%d\n",a);
	return 0;
}