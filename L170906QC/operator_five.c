#include <stdio.h>
/*
"?":唯一三元(三个操作数)符号
*/
int main(int argc, char const *argv[])
{
	//int a=5,b=6;
	//printf("%d\n",a+b?a<6?a++:++a:++b);//嵌套"?"
	//printf("%d\n",b%3?a<6?a++:++a:++b);

    //(,)
	//int i_a=(1,2,3,4);//获取最后一个值
	//printf("i_a=%d\n",i_a);
	// int i_a[3]={(1,2,3)};//只给数组第一个元素赋值,其后元素值为0
	// printf("%d\n",i_a[0]);
	// printf("%d\n",i_a[1]);
	// printf("%d\n",i_a[2]);
	// int a[][3]={{(1,2)},{(4,5)}};
	// printf("%d\n",a[0][0]);
	// printf("%d\n",a[1][0]);
	// int i_a=4;
	// int i_b=5;
	// int i_c=(i_a++,++i_b,i_a+i_b);//获取最后一个表达式值,前面表达式计算
	// printf("%d\n",i_c);
	//= +=  -=  *=
    // int i_a=5;
    // int i_b=6;
    // int i_c=1;
    // i_c*=++i_a+i_b++;//赋值语句 A=B  B==>(++i_a+i_b++)
    // //i_c=i_c*(++i_a+i_b++);
    // printf("i_c=%d\n",i_c);
	return 0;
}