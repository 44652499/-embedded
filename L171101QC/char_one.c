#include  <stdio.h>
/*
字符(char):yong '' 括起表示字符,'a' '0' '\0'
字符以ascii 编码值,常规ascii 占用1byte,最高位为0,可以表示127个字符
'a' :97
'A' 65
'0' 48
'\0' 0
 '\"'  34
 有时需要使用\  转义表示字符
 转义字符:1.不能直接输出 '\a'  '\b'  '\n'  '\t' 
         2.与表示转义字符 冲突  '\\'  '\''  '\"'

字符数组表示多个字符
*/
int main(int argc,const char* argv)
{
    //char *s = "char *s=%c%s%c;main(){printf(s,34,s,34);}";
    //printf(s,34,s,34);
    //"char *s=%c%s%c;main(){printf(s,34,s,34);}",34,s,34
    //char *s="char *s=%c%s%c;main(){printf(s,34,s,34);}";main(){printf(s,34,s,34);}",34,s,34
    //printf("abcd%c%s%c",'1',"999",'2');

    //char  char[]={'1','2','3'};//不建议
    // char  ch[]="123";//""表示多个字符
    // char  ch2[]="";//空字符,里面至少一个字符'\0','\0'作为字符数组结束标志
    // char   ch3[10];
    // scanf("%s",ch3);//输入时根据 回车键 或空格键结束,自动在数组中添加'\0'
    // printf("%s\n",ch3);//从数组首元素开始输出名,遇到'\0'结束

    char  ch4[]={'1',0,'\0','4'};// 0   '\0' 表示 '\0'  结束
    printf("%s\n",ch4);
    return 0l;
}