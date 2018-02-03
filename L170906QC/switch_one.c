#include  <stdio.h>
/*switch  case :开关语句
开关变量可以使哪些数据类型?char  short  int  enum

开关语句注意点:
1.列举值必须唯一确定值
2.开关执行语句遇到break结束,否则继续往下执行
break:用在switch case  和循环中
return:用在函数中
continue:用在循环中
*/
int main(int argc, char const *argv[])
{
	int a=0;
	switch(a)
	{
		default:printf(">3\n");break;
		case 1:
		case 0:printf("0\n");break;		
		case 2:printf("2\n");break;//结束开关语句
		//case 2:printf("2\n");return;//结束当前函数
		//case 2:printf("2\n");continue;/错误
		case 3:printf("3\n");break;		
	}
	//printf("end\n");
	return 0;
}