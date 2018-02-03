#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
二进制文件读写:
*/
int main(int argc,const char* argv[])
{
    //FILE * fp=fopen("int.dat","wt");
   // FILE * fp=fopen("int2.dat","wb");
   //FILE * fp=fopen("int2.dat","rb");
   FILE * fp=fopen("int.dat","rt");
    if(fp==NULL)
    {
        perror("fopen fail:");
        return -1;
    }
   // int  array[]={1,2,3,4,5,6,7,8,9};
    //fwrite(array,sizeof(int),9,fp);

    int array[9];
    fread(array,sizeof(int),9,fp);
    int i;
    for(i=0;i<9;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}