#include <stdio.h>
/*
字符数组与指针:

'a'  "a"区别?
'a'表示的就是字符
"a":表示两个字符,一个可见字符'a',一个不可见字符'\0'表示结束字符
'\0':算一个字符,作为字符数组或字符指针指向字符集合结束字符
*/
int main(int argc,const char* argv[])
{
//    char  ch[5]={'a','b','c','1','3'};
//    int i;
//    for(i=0;i<5;i++)
//    {
//        printf("%c",ch[i]);
//    }

//    char  ch[20];
//    scanf("%s",ch);
//    //"%s",获取字符数组第一元素地址,输入空格或回车字符结束并前面输入值后添加\0
//    printf("%s",ch);//从数组第一个元开始输出,遇到\0结束

   //char ch[]={'a','b','c','\0','d','e'};
  // char  ch[]="abcde";//'a''b''c''d''e''\0'
   //char* ptr_ch="abcde";
//    printf("%s\n",ch);
//    printf("%s\n",ptr_ch);
//    printf("%d\n",sizeof(ch));//ch数组,5个可见字符+'\0'
//    printf("%d\n",sizeof(ptr_ch));
   // char  ch2[]="abcde";//"abcde"存储在栈
   // char* ptr_ch2="abcde";//"abcde"存储在代码短的常量字符表中,唯一只读
    // if(ch==ch2)
    // {
    //     printf("ch==ch2\n");
    // }

    // if(ptr_ch==ptr_ch2)
    // {
    //     printf("ptr_ch==ptr_ch2\n");
    // }
    //*ptr_ch2='1';//不能修改常量字符表中的值

    //char *  ptr_ch="abcde";
    // char *  ptr_ch;
    // scanf("%s",ptr_ch);//错误,使用未指向的指针
    // printf("%s\n",ptr_ch);

    char ch[10]="abcdef";
    //ch[3]=0;//ch[3]='\0'
    ch[3]='0';//ch[3]=48
    printf("%s\n",ch);
   return 0;
}