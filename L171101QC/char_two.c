#include  <stdio.h>
#include  <string.h>
/*
字符数组占用空间数与字符长度关系:

*/
int main(int argc,const char* argv)
{   
    // char  ch[]="12312";
    // printf("%d\n",sizeof(ch));//计算数组空间数
    // //'\0'占用存储空间 :'1' '2' '3' '1' '2' '\0' 
    // printf("%d\n",strlen(ch));//计算字符长度
    // //从首元开始计数,遇到\0结束统计,'\0'不记录统计

    //转字符存在八进制 和16进制表示
    //八进制表示:3个八进制位表示所有字符ascii编码值,\000 表示一个字符
    //16 进制表示:2个16进制表示,\xaa 表示一个字符
    //char  ch="12\0312";//'1'  '2'  '\031'  '2'  '\0'
    //char  ch[]="12\018312";//'1'  '2'  '\01' '8'  '2'  '\0'
    //char  ch[]="12\x11"; //' 1'  '2'  'x11'  '\0'//
    //如果 \x11  后续字符将舍弃
    char  ch[]="\x12\x34\x56\x78"; 
    printf("%d\n",sizeof(ch));
    printf("%d\n",strlen(ch));
    printf("%X\n",*((int*)ch));
    return  0;
}