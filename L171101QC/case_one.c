#include <stdio.h> 
int  main (int argc,const char* argv[])
{
    int c;
    while((c=getchar())!='\n')
    switch(c-'2')//switch 变量类型只能是:int char enum
    {
        case 0:
        case 1:putchar(c+4);
        case 2:putchar(c+4);return;//break;//出现break 结束
        case 3:putchar(c+3);
        case 4:putchar(c+2);break;
    }
    printf("\n");
}