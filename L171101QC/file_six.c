//实现cp    d_file s_file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void   define_cp(const char *  destfile,const char* srcfile)
{
    FILE * pdest=fopen(destfile,"wt");
    if(pdest==NULL)
    {
        perror("fopen destfile :");
        return;
    }
    FILE *psrc=fopen(srcfile,"rt");
    if(psrc==NULL)
    {
        perror("fopen srcfile:");
        return;
    }
    char buf[1024];
    while(!feof(psrc))
    {
        bzero(buf,sizeof(buf));
        fread(buf,sizeof(char),sizeof(buf)-1,psrc);
        fwrite(buf,sizeof(char),strlen(buf),pdest);
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