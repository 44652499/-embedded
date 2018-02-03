#include <stdio.h>
#include <stdarg.h>
//省略号参数问题
void fun(char *fmt,...)///int  char char *
{
  printf("hello\n");
  va_list aap;
  va_start(aap,fmt);
  char * p=fmt;
  char *s;
  char c;
  int d;
  while(1)
  {
    if(*fmt=='\0')
    {
      break;
    }
    switch(*fmt)
    {
      case 's':
                  s=va_arg(aap,char *);
                  printf("string %s\n",s);
                  break;
      case 'd':
                  d=va_arg(aap,int);
                  printf("int %d\n",d);
                  break;
      case 'c':
                  c=(char)va_arg(aap,int);
                  printf("char %c\n",c);
                  break;
      default:break;
    }
    fmt++;
  }
  va_end(aap);
}
int main(int argc, char const *argv[]) {
  char *fmt="dcss";
  int d=210;
  char c='a';
  char *name="zhouyetian";
  char *name2="zhouyetian11";
  fun(fmt,d,c,name,name2);
  return 0;
}
