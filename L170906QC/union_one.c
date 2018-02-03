#include <stdio.h>
#include <string.h>
/*联合体:自定义数据类型,由多个子元素组成,所有子元素共用一个空间.最大的子元素空间*/
// union  A
// {
//     int a;
//     char ch;
// };

// union  A
// {
//     int a;
//     char ch[10];
// };

// typedef union  
// {
//     int a;
//     char ch;
// }A;

// typedef union 
// {
// 	int num;
// 	char ch[2];
// }A;


// union T
// {
// 	int a;
// 	char b;
// };

// union 
// {
//     char a[2];
//     int i;
// }u,*p;

union uni
{
   struct
   {
      char* p3;
      int n4;
   }s1;
   
   struct
   {
      char* p5;
      int n6;
      int n7;
    }s2;
};


struct node 
{
  int a;
  int b;
  int c;     
};

int main(int argc, char const *argv[])
{
   // printf("%d\n",sizeof(union  A));//只分配最大元素,并且使用内存对齐
    // A  obj;
    // obj.a=300;//100101100
    // printf("%d\n",obj.ch);//obj.a,obj.ch 访问的是同一空间起始地址,根据类型计算结束地址

    // A a;
	// a.num=1;
	// a.ch[0]=1;
	// a.ch[1]=2;
    // printf("%d\n",a.num);
    
    // union T t1;
	// t1.a=256;
    // printf("%d\n",t1.b);	
    
    // p = &u;
	// p->a[0] = 0x39;
	// p->a[1] = 0x1;
    // printf("%x\n",p->i);
    
    // union uni u;
    // u.s1.p3=(char*)&u.s2.n7;
    // u.s2.p5=(char*)&u.s2.n6;
    // u.s2.n6=0x11111111;
    // u.s2.n7=0xffffffff;
    // u.s1.n4=0x22222222;
    // printf("%d %d",sizeof(u),sizeof(&u));
    // printf("%d",(int*)&u.s1.n4-(int*)&u.s2.p5);
    // printf("%d\n",*u.s1.p3);

    struct node  s= { 3, 5,6 };
    struct node *pt = &s;
    printf("%d" ,  *(int*)pt);
    return 0;
}