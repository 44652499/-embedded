//实现cp    d_file s_file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void   define_cp(const char *  destfile,const char* srcfile)
{
    FILE * pdest=fopen(destfile,"wb");
    if(pdest==NULL)
    {
        perror("fopen destfile :");
        return;
    }
    FILE *psrc=fopen(srcfile,"rb");
    if(psrc==NULL)
    {
        perror("fopen srcfile:");
        return;
    }
    char buf[1024];
   // while(!feof(psrc))//针对图片读取,结束标志不一定与字符文件结束字符一样,有可能是图片中一个正常字符
   while(1)
    {
        bzero(buf,sizeof(buf));
        int ret=fread(buf,sizeof(char),sizeof(buf),psrc);
        if(ret==0)
          break;
        fwrite(buf,sizeof(char),ret,pdest);
    }
    fclose(pdest);
    fclose(psrc);
}
int main(int argc,const char* argv[])
{
    char destfilename[20],srcfilename[20];
    gets(destfilename);
    gets(srcfilename);
    define_cp(destfilename,srcfilename);
    return 0;
}