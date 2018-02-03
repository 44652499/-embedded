#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
/*
作业:假如2017年1月1是星期日,请用程序输出2017,2018年日历
实现功能前必须实现一个小功能:计算今天是今年第几天?
*/
//定义日期类型
typedef struct 
{
    int  year;
    int month;
    int day;
}date;
//判断是否是闰年
int is_leap_year(date  curr_date)
{
    if(curr_date.year%4==0 && curr_date.year%100!=0 || curr_date.year%400==0)
    {
        return  1;
    }
    return 0;
}
//计算今天是今年的第几天
int   get_daysofyear(date  curr_date)
{
    int daysofyear=0;
    int daysofmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    for(i=0;i<curr_date.month;i++)
    {
        daysofyear+=daysofmonth[i];
    }
    if(curr_date.month>2)
    {
        if(is_leap_year(curr_date))
        {
            daysofyear=daysofyear+1;
        }        
    }
    return daysofyear+curr_date.day;
}

int main(int argc, char const *argv[])
{
    date  c_date;
    c_date.year=2017;
    c_date.month=11;
    c_date.day=15;
    printf("%d\n",get_daysofyear(c_date));
    return  0;
}