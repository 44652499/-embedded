#include <stdio.h>
int g_data=20;
int g_data_one;
const int g_data_three=30;
const int g_data_four;
int main(int argc, char const *argv[])
{
	int l_a;
	const int l_b;
	char* ptr_ch="abcd";
	printf("%X\t%X\t%X\n",&g_data,&g_data_three,ptr_ch);
	printf("%X\t%X\n",&g_data_one,&g_data_four);
	printf("%X\n",&main);
	printf("%X\t%X\n",&l_a,&l_b);
	return 0;
}

// #define  A(a,b)  a##b
// #define  B(a)   #a
// //#define  C(a,b)  (a)(b) 
// #define  C(a,b)  ab    //ab为一个新的标识符
// #define  D(a,b)  #a##b

// #define E(a,b) a##b 
// #define D(a) #a 
// #define S(a) D(a) 
// int main(int argc, char const *argv[])
// {
// 	// A(1,2);
// 	// B(34);
// 	// A(1+4,2*5);//1+42*5
// 	// //C(1+4,2*5);
// 	// D(1+4,2*5);//"1+4"2*5

// 	D(E(a,b)); 
// 	S(E(a,b));
// 	return 0;
// }

//#define  A
//#define  OS    window

//#define  B 

// #ifdef A
//   #error("A  is  error")  //预编译错误提示
// #endif

// int main(int argc, char const *argv[])
// {
// 	// #ifdef 	A 
// 	//    printf("defined  A\n");
// 	// #else
// 	//    printf("not define A\n");
// 	// #endif

// 	// #if A==window
// 	//    printf("window os\n");
// 	// #else
// 	//    printf("linux os\n");
// 	// #endif


// 	#ifdef B
// 	  printf("defined  B\n");
// 	#else
// 	  printf("not define A\n");
// 	#endif
// 	// gcc  -D  B   macro10.c  -o a.out  //-D   B  相当于 #define  B

// 	// #ifdef  A
// 	//    printf("defined  A\n");
// 	// #else
// 	//    printf("not define A\n");
//  //    #endif

// 	// #undef A//取消定义

//  //    #ifdef  A
// 	//    printf("defined  A\n");
// 	// #else
// 	//    printf("not define A\n");
//  //    #endif
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	return 0;
// }