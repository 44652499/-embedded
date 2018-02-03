#include <stdio.h>
#include <string.h>
/*
字符数组字符长度与字符数组存储空间:
strlen  与 sizeof  区别?
strlen:统计字符数组中字符数,遇到'\0'结束统计,'\0'计算
sizeof:字符数组空间数,每个字符都要存储空间

转义字符:\字符  ,表示一个特殊字符.表示不能输出字符本身,表示特殊输出效果>如:\n  \t \b \a \\  \'   \"   \0xx
*/
int main(int argc,const char* argv[])
{
    // char  ch[]="abc\0der";
    // char  *ptr_ch="abcder";
    // printf("%d\t%d\n",strlen(ch),sizeof(ch));//"\0"结束并不计算
    // printf("%d\t%d\n",strlen(ptr_ch),sizeof(ptr_ch));

    // char ch1[]="abcd";
    // char ch2[5]="abc";
    // char ch3[5]="abcde";
    // printf("%d\t%d\n",strlen(ch1),sizeof(ch1));
    // printf("%d\t%d\n",strlen(ch2),sizeof(ch2));
    // printf("%d\t%d\n",strlen(ch3),sizeof(ch3));
    //strlen(ch3)计算结果不正确,数组ch3内没有'\0'
    //输出: \  '  "
    //printf("%c\n",'\\');
    //printf("%c\n",'\'');
    //printf("%c\n",'\"');
   // char  *ch="\012";//"\0xx"用三位八进制表示字符asii编码值
    //char  *ch="12\012adf";
    //char  *ch="\08888adf";//'\0'长度为0, '8'不是一个八进制字符
    //char *ch="\x12\x56\xab";//"\xnn" 用两个16进制字符表示字符asii编码值
    //printf("%d\n",strlen(ch));

    // char  *ch="\x12\x34\x56\x78";
    // int *p=(int*)ch;
    // printf("%X\n",*p);
    return 0;
}