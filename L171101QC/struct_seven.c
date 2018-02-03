#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
/*
计算今天是本年的第几天
*/
//定义日期结构
typedef struct 
{
	int year;
	int month;
	int day;
}date;
//判断是否是闰年
int  isleapyear(date d)
{
	if(d.year%4==0 &&  d.year%100!=0  || d.year%400==0)
	{
    	return 1;
	}
	return 0;
} 
//计算函数
int  dayofyear(date d)
{
	int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int sumdays=0;
    for(i=1;i<d.month;i++)
    {
    	sumdays+=days[i];
    }
    if(d.month>2)
    {
    	if(isleapyear(d))
        {
    	   sumdays+=1;
        }
    }
    return sumdays+d.day;
   
}
int main(int argc, char const *argv[])
{
	date d={2017,12,31};
	printf("%d\n",dayofyear(d));
	return 0;
}
//假如2018年1月1日是星期1,请用程序输出万年历(2050年)