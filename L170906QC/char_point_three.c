#include <stdio.h>
#include <string.h>
//实现strlen 函数
int  define_strlen(const char*  str)
{
    int counter=0;
    while(*str!='\0')
    {
        counter++;
        str++;
    }
    return counter;
}

//实现strcpy函数
char*  define_strcpy(char * dest,const char* src)
{
    char *  ptr_ret=dest;
    while(*src!='\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
   // *dest='\0';//复制结束后必须添加'\0'
    return ptr_ret;
}

//实现strcpy函数
char*  define_strcpy_new(char  dest[5],const char* src,int dest_size)
{
    //dest已经退化成指针;,不能判断空间数够不够
    // if(sizeof(dest)<strlen(src))
    // {

    // }
    int i=0;
    while(*(src+i)!='\0')
    {
        *(dest+i)=*(src+i);
        i++;
        if(i==dest_size-1)
           break;
    }
    *(dest+i)=0;
    return dest;
}

//实现strncpy
char *  define_strncpy(char* dest,const char* src,size_t n)
{
    char* ptr_ret=dest;
    int cnt=1;
    while(cnt<=n)
    {
        if(*src=='\0')
          break;
        *dest++=*src++;
        cnt++;
    }
    *dest='\0';
    return ptr_ret;
}
//自定义字符比较大小
//比较大小规则:首先出现字符大则大,与长度无关.字符比较大小就是比较ASCII编码值
//自定义
//1245 1245
int   define_strcmp(const char* src1,const char* src2)
{
    int ret=0;
    while(1)
    {
        if(*src1>*src2)
        {
            ret=1;
            return ret;
        }
        if(*src1<*src2)
        {
            ret=-1;
            return ret;
        }
        src1++;
        src2++;
        if(*src1=='\0' &&  *src2=='\0')
        {
            return ret;
        }
    }
}

//自定义strcat
char*  define_strcat(char *  dest,const char * src)
{
    //需要,目标空间大小 sizeof(dest)=strlen(dest)+strlen(src)+1;
    char *ptr_ret=dest;
    while(*dest!=0)
    {
        dest++;
    }
    while(*src!=0)
    {
        *dest++=*src++;
    }
    *dest='\0';
    return ptr_ret;
}
int main(int argc,const char* argv[])
{
    //char  ch[]="abc\0def";
    //char ch[20];
    //scanf("%s",ch);
    //gets(ch);//只有输入'\n'结束输入
    //puts(ch);
    //printf("%d\n",define_strlen(ch));
    //char  ch;
    //ch=getchar();//输入一个字符
    //putchar(ch);//输出一个字符
    // int i;
    // char ch;
    // for(i=0;i<7;i++)
    // {
    //     scanf("%c",&ch);//循环中连续多次输入单个字符,容易造成缓存效应
    //     getchar();//清空输入缓存
    //     printf("%c",ch);
    // }
    // getchar();
   // char  ch[]="123456";
    //char  ch2[20];
    //char  ch2[20]={0};//初始化局部数组值为\0
    //字符数组赋值
    //ch2=ch;//错误
  // char *  ptr_ret=strcpy(ch2,ch);
    //用标准库函数初始化数组元素值为0
    //bzero(ch2,sizeof(ch2));
    //memset(ch2,0,sizeof(ch2));
    //define_strcpy(ch2,ch);

    //char  ch2[5];
    //strcpy(ch2,ch);//原数组的长度大于目标字符数组空间数
    //define_strcpy_new(ch2,ch,5);

    //char  ch2[20];
    //bzero(ch2,sizeof(ch2));
    //strncpy(ch2,ch,5);
    //define_strncpy(ch2,ch,10);
    //printf("%s\n",ch2);

    // char  ch1[]="1234";
    // char  ch2[]="123456789";
    //strcpy(ch1,ch2);
    // char  ch2[]="123456789";
    // char  ch1[]="1234";    
    // strcpy(ch1,ch2);
    // printf("%s\n",ch2);
    // printf("%s\n",ch1);

    //strcmp
    //int  ret=strcmp("123","aa");
   // int ret=define_strcmp("1235","1235");
    ///printf("%d\n",ret);
    //返回值:0相等  1:>  -1  <

    //strcat:在第一个参数\0之后追加新的字符数组值
    char  ch[20]="abcd";
    //char  ch[20]={0};
    char   ch2[]="123456";
    //printf("%s\n",strcat(ch,ch2));
    printf("%s\n",define_strcat(ch,ch2));
    return 0;
}
//实现strcmp 比较字符大小
