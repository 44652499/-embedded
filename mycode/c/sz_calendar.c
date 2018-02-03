//假如2011年1月1日是礼拜六,3日礼拜一,请用程序输出到2050年的日历
#include <stdio.h>
typedef  struct 
{
	int year;
	int month;
}date;

int is_leap_year(date year_month)       //right
{
   int is_leap=0;
   if((year_month.year%4==0&&year_month.year%100!=0)||year_month.year%400==0)
   {
      is_leap=1;
   }
   return is_leap;
}

void get_graph(date year_month)           
{
	date tmp2011={2011,1};
	int list_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int day_dis=0;
	int day=1;
	int feb_is_leap=0;
	int month_num_day;
	printf("\t\t%d年%d月\n",year_month.year,year_month.month);
	printf("一\t二\t三\t四\t五\t六\t日\n");
    day_dis=distance_day(tmp2011,year_month);
    if(year_month.month==2)
    {
    	feb_is_leap=is_leap_year(year_month);
    	month_num_day=list_month[year_month.month-1]+feb_is_leap;
    }   
    else
    {
    	month_num_day=list_month[year_month.month-1];
    }    
    switch(day_dis%7)
      {
    	case 0:
    	    printf("\t\t\t\t\t%d",day);
    	    break;
    	case 1:
    	    printf("\t\t\t\t\t\t%d\n",day);
    	    break;
    	case 2:
    	    printf("%d",day);
    	    break;
    	case 3:
    	    printf("\t%d",day);
    	    break;
    	case 4:
    	    printf("\t\t%d",day);
    	    break;
    	case 5:
    	    printf("\t\t\t%d",day);
    	    break;
    	case 6: 
    	    printf("\t\t\t\t%d",day);
    	    break;
    	default:
    	    break;
      }
      day_dis++;
      day++;
     while(day<=month_num_day)
     {
           switch(day_dis%7)
        {
    	  case 0:
    	    printf("\t%d",day);
    	    break;
    	  case 1:
    	    printf("\t%d\n",day);
    	    break;
    	  case 2:
    	    printf("%d",day);
    	    break;
    	  case 3:
    	    printf("\t%d",day);
    	    break;
    	  case 4:
    	    printf("\t%d",day);
    	    break;
    	  case 5:
    	    printf("\t%d",day);
    	    break;
    	  case 6: 
    	    printf("\t%d",day);
    	    break;
    	  default:
    	    break;
        }
        day_dis++;
        day++;
     }
}

int distance_day(date tmp2011,date year_month)
{
     date tmp_year_month=tmp2011;
     int list_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
     int dis_year,dis_month,dis_day=0;
     int i=0;
     int a=0,c=0;     //a临时存放is_leap_year返回值
     dis_day=0;
     dis_year=year_month.year-tmp_year_month.year;
     dis_month=year_month.month-tmp_year_month.month;
     for(i=0;i<dis_year;++i)
     {
          a=is_leap_year(tmp_year_month);
          (tmp_year_month.year)++;
          dis_day=dis_day+365+a;
     }
     //printf("%d\n",i);
     for(i=0;i<dis_month;++i)
     {
         dis_day=dis_day+list_month[i];    
     }
     a=is_leap_year(year_month);
     //printf("%d\n",i);
     if((a==1)&&(year_month.month>2))
     {
         dis_day++;
     }                
     return dis_day;
}

int main(int argc, char const *argv[])
{
    date year_month;
    printf("\t\tplease input year&month\n");
	scanf("%d,%d",&year_month.year,&year_month.month);
	get_graph(year_month);
	return 0;
}
