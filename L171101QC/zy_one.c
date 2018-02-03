#include <stdio.h>
//1.编程实现将任意的十进制整数转换成R进制数(R在2-16之间)
// int main(int argc,const char* argv[])
// {
//     int n;
//     scanf("%d",&n);
//     if(n<0)
//     {
//         n=-n;
//     }
//     int r;
//     scanf("%d",&r);
//     char  ch[]="0123456789ABCDEF";
//     int array[32];
//     int index=0;
//     while(n!=0)
//     {
//         array[index]=n%r;
//         n=n/r;
//         index++;
//     }
//     while(--index>=0)
//     {
//         printf("%c",ch[array[index]]);
//     }
//     printf("\n");
//     return 0;
// }
//3.输入10个数,请输出其中的最大值、最小值,并统计正数、负数、零的个数.
// int main(int argc,const char* argv[])
// {
//     int array[10];
//     int i;
//     for(i=0;i<10;i++)
//     {
//         scanf("%d",&array[i]);
//     }
//     int max=array[0];
//     int min=array[0];
//     for(i=1;i<10;i++)
//     {
//         if(max<array[i])
//         {
//             max=array[i];
//         }
//         if(min>array[i])
//         {
//             min=array[i];
//         }
//     }
//     printf("max=%d\tmin=%d\n",max,min);
//     return 0;
// }

//求100到1000之间有多少个其数字之和为5的整数
// int main(int argc,const char* argv[])
// {
//     int i;
//     for(i=100;i<1000;i++)
//     {
//         int a=i%10;
//         int b=i/10%10;
//         int c=i/100%10;
//         if(a+b+c==5)
//         {
//             printf("%d\n",i);
//         }
//     }
// }

//计算斐波那契分数序列前n项之和(n是某个常数).( 2/1,3/2,5/3,8/5,13/8,21/13,...... 前一项的分子作为后一项的分母.前一项的分分母和作为后一项的分母)
// int main(int argc,const char* argv[])
// {
//     int n;
//     scanf("%d",&n);
//     int i;
//     double sum=0;
//     int m=2;
//     for(i=0;i<n;i++)
//     {
//       //sum+=(double)m/(i+1);
//       sum+=m/(i+1.0);
//       m=m+(i+1);
//     }
//     printf("%f\n",sum);
//     return 0;
// }

//一球从100米高度自由落下,每次落地后反跳回原高度的一半;再落下,求它在第10次落地时,共经过多少米?第10次反弹多高?
// int main(int argc,const char* argv[])
// {
//     int i;
//     double height=100;
//     double sum=100;
//     for(i=0;i<10;i++)
//     {
//         height=height/2;
//         sum+=height*2;
//     }
//     printf("%f\t%f\n",sum,height);
//     return 0;
// }

//将一个正整数分解质因数.例如:输入90,打印出90=2*3*3*5.
int main(int argc,const char* argv[])
{
    int data;
    scanf("%d",&data);
    int n=2;
    while(data!=1)
    {
        while(data%n==0)
        {
            data=data/n; 
            if(data==1)
            {
                printf("%d",n);   
            } 
            else
            {
                printf("%d*",n);   
            }
                             
        }
        n++;
    }
    return 0;
}