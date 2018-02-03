#include <stdio.h>
int main(int argc,const char* argv[])
{
    printf("%c",'\n');
    printf("%c",'\\');
    printf("%s","\\n");//去特殊字符处理
    //printf("%c",'\\n');
    printf("%s","/\n");
    return 0;
}