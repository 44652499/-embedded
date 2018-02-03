#include <stdio.h>
#define A(x,y)  x##y
#define B(x,y)  #y
#define C(x,y)  #x##y
//#define D(x,y)  #(x##y)//错误,"#"后必须接宏参数
//#define E(y)    #y

#define E(a,b) a##b 
#define D(a) #a 
#define S(a) d(a) 


//#define B
//编译错误提示
#define AA
// #ifdef AA
// #error "this is error"
// #endif


// #define os win
// #if os==win
//     #include"win.h"
// #elif os==Linux
//     #include"linux.h"
// #elif os==mac
//     #include"mac.h"
// #endif

int main(int argc, char const *argv[])
{
	int a=20,b=30;
	//A(a,b);
	//A(10,20);
    //B(a,10);
    //C(a,b);
    //D(a,b);
	//E(A(a,b));//"A(a,b)"  #后面参数当做字符处理
	//d(f(a,b)); 
    //s(f(a,b));
    //E(1+2,3+4);

    //#ifdef B
    // #ifdef AA
    //    printf("212323\n");
    // #endif 

    #ifdef A1
      printf ("macro A1\n");
    #else
      printf("macro not A1\n");
    #endif
	return 0;
}
//[root@localhost 160904c]# gcc macro_test.c  -D A1 -o test
//[root@localhost 160904c]# gcc macro_test.c  -o test

/*
1.求最大值和最小值
#define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
2.得到一个字的高位和低位字节
#define  WORD_LO(***)  ((byte) ((word)(***) & 255))
#define  WORD_HI(***)  ((byte) ((word)(***) >> 8))
3.将一个字母转换为大写
#define  UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )
4.判断字符是不是10进值的数字
#define  DECCHK( c ) ((c) >= '0' && (c) <= '9')
5.判断字符是不是16进值的数字
#define  HEXCHK( c ) ( ((c) >= '0' && (c) <= '9') ||\
                       ((c) >= 'A' && (c) <= 'F') ||\
((c) >= 'a' && (c) <= 'f') )
6.防止溢出的一个方法
#define  INC_SAT( val )  (val = ((val)+1 > (val)) ? (val)+1 : (val))
7.返回数组元素的个数
#define  ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )
*/
