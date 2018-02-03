#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//自定义结构体
typedef struct student
{
    int sid;
    char sname[20];
}student;
//写文件
void  write_file(const char* filename,student *pstudent,int len)
{
    FILE * fp=fopen(filename,"wb");
    if(fp==NULL)
    {
        perror("fopen fail:");
        return;
    }
    // int i;
    // for(i=0;i<len;i++)
    // {
    //     fwrite(pstudent+i,sizeof(student),1,fp);//一次只写一个学生
    // }
    fwrite(pstudent,sizeof(student),len,fp);
    fclose(fp);
}
//读文件
student*  read_file(const char*  filename)
{
    FILE * fp=fopen(filename,"rb");
    if(fp==NULL)
    {
        perror("fopen fail:");
        return NULL;
    }
    student*  pstudent=(student*)malloc(10*sizeof(student));
    assert(pstudent!=NULL);
    // int i;
    // for(i=0;i<10;i++)
    // {
    //     fread(&pstudent[i],sizeof(student),1,fp);
    // }
     fread(pstudent,sizeof(student),10,fp);
    fclose(fp);
    return pstudent;
}
int main(int argc,const char * argv[])
{
    char filename[20];
    gets(filename);
    student stuarray[10];
    int  i;
    for(i=0;i<10;i++)
    {
        stuarray[i].sid=i+1;
        sprintf(stuarray[i].sname,"student%d",i+1);
    }
    write_file(filename,stuarray,10);
    student *pstu=read_file(filename);
    for(i=0;i<10;i++)
    {
        printf("%d\t%s\n",stuarray[i].sid,stuarray[i].sname);
    }
    return 0;
}