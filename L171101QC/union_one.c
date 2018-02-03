#include  <stdio.h>
#include  <string.h>
/*
联合体:自定义数据类型.让多个不同类型成员共享同一块内存
根据最大成员分配一块足够内存,其它成员都可以访问.所有成员同步更新内存空间
*/
union  student
{
	int sid;
	char sname[10];//根据sname分配并对齐
};

// typedef union 
// {
// 	int num;
// 	//char ch[2];
// 	char  ch;
// }A;

// union T
// {
// 	int a;
// 	char b;
// };




int main(int argc, char const *argv[])
{
	union  student  u1;
	// u1.sid=0x12345678;
	// strcpy(u1.sname,"1234567");//改写空间值
	// printf("%d\n",u1.sid);
	//printf("%d\n",sizeof(u1));
	// A a;
	// a.num=1;
	// a.ch[0]=1;
	// a.ch[1]=2;
	// printf("%d\n",a.num);


	// A  a;
	// a.num=0x12345678;
	// int i;
	// for(i=0;i<4;i++)
	// {
	// 	printf("%X\n",*(&(a.ch)+i));
	// }

	// union T t1;
	// t1.a=256;
	// printf("%d\n",t1.b);	

    //实现把无符号的长整数,拆分成两个无符号短整数
	// unsigned long dat=0x12345678ul;
	// unsigned short *  ptr=(unsigned short*)&dat;
	// printf("%X\n",*ptr);
	// printf("%X\n",*(ptr+1));
	// typedef union  
	// {
	// 	unsigned long dat;
	// 	unsigned short  sdat;
	// }A;
	// A a1;
	// a1.dat=0x12345678ul;
	// printf("%X\n",a1.sdat);
	// printf("%X\n",*(&(a1.sdat)+1));

	// union 
	// {
	//     char a[2];
	// 	int i;
	// }u,*p;
	// p = &u;
	// p->i=0;//清0
	// p->a[0] = 0x39;
	// p->a[1] = 0x1;
	// printf("%x\n",p->i);

	// union uni
 //    {
 //      struct
 //      {
 //      char* p3;
 //      int n4;
 //      }s1;
   
 //     struct
 //     {
 //      char* p5;
 //      int n6;
 //      int n7;
 //    }s2;
 //   };
 //   union uni u;
 //   u.s1.p3=(char*)&u.s2.n7;
 //   u.s2.p5=(char*)&u.s2.n6;
 //   u.s2.n6=0x11111111;
 //   u.s2.n7=0xffffffff;
 //   u.s1.n4=0x22222222;
 //   printf("%d %d\n",sizeof(u),sizeof(&u));
 //   printf("%d\n",(int*)&u.s1.n4-(int*)&u.s2.p5);//计算相差空间数
 //   printf("%d\n",(int)&u.s1.n4-(int)&u.s2.p5);//计算相差字节数字节
 //   printf("%d\n",*u.s1.p3);//char* p3 ,只取第一个字节

   char data[1000];
   int i;
   for(i=0;i<1000;i++)
   {
      data[i]=-1-i;
   }
   printf("%d\n",strlen(data));//data[0]=0
	return 0;
}