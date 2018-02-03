#include <stdio.h>
/*
有一个16位的无符号短整数，每4位为一个数，写函数求他们的和
1001 1100 0011 0101
 9  +  12  +  3  +  5=?   
 200:
 1100 1000
*/
// int main(int argc,const char* argv[])
// {
//     unsigned short data;
//     scanf("%hu",&data);//输入无符号短整数
//     int array[]={1,2,4,8};
//     int sum=0;
//     int index=0;
//     while(data!=0)
//     {
//         unsigned short  tmp=data&0xf;
//         index=0;
//         while(tmp!=0)
//         {
//             if(tmp&0x1)
//             {
//                 sum+=array[index];
//             }
//             index++;
//             tmp=tmp>>1;
//         }
//         data=data>>4;
//     }
//     printf("%d",sum);
//     return 0;
// }


//2.写一个函数，对一个16位的二进制数取出他的奇数位
// int main(int argc,const char* argv[])
// {
//     unsigned short data;
//     scanf("%hu",&data);//输入无符号短整数
//     int array[8];
//     int index=0;
//     while(data!=0)
//     {
//       if(data&0x1)
//       {
//           array[index]=1;
//       }
//       else
//       {
//           array[index]=0;
//       }
//       index++;
//       data=data>>2;
//     }
//     while(--index>=0)
//     {
//         printf("%d",array[index]);
//     }
//     printf("\n");
//     return 0;
// }

//3.利用位运算,实现数字转换(十进制转换成二进制)
// int main(int argc,const char* argv[])
// {
//     unsigned short data;
//     scanf("%hu",&data);
//     int array[16];
//     int index=0;
//     while(data!=0)
//     {
//         array[index++]=data&0x1;
//         data=data>>1;
//     }
//     while(--index>=0)
//     {
//         printf("%d",array[index]);
//     }
//     printf("\n");
//     return 0;
// }

//输一个无符号整数,请统计该数对应二进制中1的个数
// int main(int argc,const char* argv[])
// {
//     unsigned short data;
//     scanf("%hu",&data);
//     int cnt=0;
//     while(data!=0)
//     {
//         if(data&0x1)
//         {
//             cnt++;
//         }
//         data=data>>1;
//     }
//     printf("%d\n",cnt);
//     return 0;
// }
//假如存在一个整数 x,一般是是以小端模式存储,如何将x转换成大端模式存储
//小端模式:低位数据存储低地址
//大端模式:低位数据存储高地址
int main(int argc,const char* argv[])
{
    int data=0x12345678;
    printf("%X\n",data);
    //小端模式换大端模式
    data=((data&0xff)<<24)|((data&0xff00)<<8)|((data&0xff0000)>>8)|((data&0xff000000)>>24);
    printf("%X\n",data);//0x78563412
    return 0;
}

