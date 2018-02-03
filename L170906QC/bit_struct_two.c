#include <stdio.h>

int main(int argc, char const *argv[])
{
//     union
//     {
//     struct student
//     {
//       unsigned char s1:1;
//       unsigned char s2:3;
//     }x;
//     unsigned char c;
//     }v;
//     v.c=0;
//     v.x.s1=0;
//     v.x.s2=4;
//    printf("%d\n",v.c);
//    printf("%d\n",sizeof(v)); 

        // union
        // {
        // struct student
        // {
        // unsigned char s1:1;
        // unsigned char s2:2;
        // unsigned char s3:2;
        // }x;
        // unsigned char c;
        // }v;
        // v.c=0;
        // v.x.s1=0;
        // v.x.s3=2;
        // printf("%d\n",v.c);
        // printf("%d\n",sizeof(v));  

        typedef struct bit 
        {   
            int a:3;
            int b:2; 
            int c:3; 
        }bit; 
        bit s; 
        char *c=(char*)&s; 
        printf("%d\n",sizeof(bit));
        *c=0x99;
        printf("s.a=%d\ts.b=%d\ts.c=%d\n",s.a,s.b,s.c);
        int a=-1;
        printf("%x\n",a);
        return 0;
}