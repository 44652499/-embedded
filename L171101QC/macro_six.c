#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
参数宏使用 :#  ##表示什么含义
#:相当于使用""括起参数值
##:相当于连接参数值

实现编译错误消息输出:
*/
#define  A(a)  #a
#define  B(a,b) a##b
#define  C(a,b) a##b
#define  D(a,b) (a)##(b)
//#define  E(a,b) #a##(b)  #后面必须接参数
#define  E(a,b)  //从左到右完成

// #define E(a,b) a##b 
// #define D(a) #a 
// #define S(a) D(a)

#define  DEBUG_MSG(condition)     \
              if(!(condition))  \
              { \
                debug_error(__FILE__,__LINE__,"error",#condition); \
              }


void  debug_error(const char* filename,int line,const char* title,const char * error)
{
    printf("%s:%d:%s:%s\n",filename,line,title,error);
    abort();
}

int main(int argc,const char * argv[])
{
    // char *ch=A(abcd);
    // int data=B(1,2);
    // C(1*2,4+6)//1*24+6
    // D(1*2,4+6)
    // E(1*2,4+6);
   // D(E(a,b)); //"E(a,b)"  E(a,b)就是参数 a  #a  "E(a,b)"双引号中的宏不再解析
    //S(E(a,b));  //"ab" 

    DEBUG_MSG(2==3);

    //assert(2==3);
    printf("end\n");
    return 0;
}
//黎刚 :分析const  #define 区别?