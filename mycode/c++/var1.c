#include <stdio.h>
int g_data1;
int g_data2;
const int g_data3;

int v_data1=1;
int v_data2=2;
const int v_data3=3;
int main(int argc, char const *argv[])
{
	printf("g_data1=%X\tg_data2=%X\tg_data3=%X\n",&g_data1,&g_data2,&g_data3);
	printf("v_data1=%X\tv_data2=%X\tv_data3=%X\n",&v_data1,&v_data2,&v_data3);
    char * str="abcd";
    printf("main=%X\tstr=%X\n",&main,str);
	//printf("g_data1=%X\tg_data2=%X\n",&g_data1,&g_data2);
	//printf("v_data1=%X\tv_data2=%X\n",&v_data1,&v_data2);
	int l_data;
	const l_data2;
	printf("l_data=%X\tl_data2=%X\n",&l_data,&l_data2);
	return 0;
}