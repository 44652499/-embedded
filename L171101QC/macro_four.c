#include <stdio.h>
//输出两个数的最大值与最小值
#define  MAX(a,b)  ((a)>(b)?(a):(b))
//把小写字母转换成大写
#define  TOUPPER(a)  (((a)>='a'&& (a)<='z')?(a)-32:(a)) 
//#define  TOUPER(a)  if((a)>='a' && (a)<='z'){ printf("%c",(a)-32);} else {printf("%c\n",(a));} 
//长语句写法,一般使用"\"取消换行字符
#define  TOUPER(a)  if((a)>='a' && (a)<='z') \
                    {  \
                        printf("%c",(a)-32); \
                    } \
                    else \
                    {\
                        printf("%c\n",(a));\
                    } 
//判断是否是十进制数字字符
#define  ISDIGIT(a)  (((a)>='0'&&(a)<='9')?'y':'n')
//判断是否是16进制字符
#define  ISHEXCHAR(a) ((a)>='0' && ((a)<='9' || (a)>='a'&&(a)<='e' || (a)>='A' && (a)<='E'))?'y':'n'
//输出数组的元素的个数
#define ARRAY_N(a) (sizeof(a)/sizeof(a[0]))
#define equal(a,b) a==b
int main(int argc,const char* argv[])
{
    int a=3,b=7;
    printf("%d",equal(a&3,3&&b));
    //int d1=MAX(2,3);
    //int d2=MAX(4+5,3*6);
    //printf("%d\t%d\n",d1,d2);
    //printf("%c\n",TOUPPER('b'));
    //TOUPER('b')
    //printf("%c\n",ISDIGIT('a'));
    //printf("%c\n",ISHEXCHAR('.'));
    // int array[10];
    // char  ch[10];
    // printf("%d\n",ARRAY_N(array));
    // printf("%d\n",ARRAY_N(ch));
    return 0;
}