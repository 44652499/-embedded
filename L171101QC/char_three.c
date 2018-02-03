#include  <stdio.h>
#include  <string.h>
/*

*/
//自定义strlen
// size_t strlen(const char *s); 系统原型
int  define_strlen(const char * ch)  //const char * 防止在函数中更改实参值
{
   int cnt=0;
   while(*ch!='\0')
   {
       cnt++;
       ch++;
    }
    return cnt;  
}

//实现strcpy
//char *  strcpy(char *dest, const char *src);
void   define_strcpy(char * dest,const char* src)
{
    while(*src!='\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest=0;//填入'\0'
}

void*  define_strncpy(char *  dest,const char* src,int n)
{
    while(1)
    {
        if(*src==0)
        {
            break;
        }
        if(n==0)
        {
            break;
        }
        *dest++=*src++;
        n--;
    }
    *dest='\0';
}

char *  define_strncpy2(char *  dest,const char* src,int n)
{
    char*  ptr_ret=dest;
    while(1)
    {
        if(*src==0)
        {
            break;
        }
        if(n==0)
        {
            break;
        }
        *dest++=*src++;
        n--;
    }
    *dest='\0';
    return ptr_ret;
}

int main(int argc,const char* argv)
{   
    // char ch[]="12345";
    // char ch2[6]="1234";
    // char ch3[6]="123456";//strlen(ch3)  ,在ch3 空间内没有\0,strlen 函数继续往下读取字符直到出现'\0'结束
    // printf("%d\t%d\n",sizeof(ch),strlen(ch));
    // printf("%d\t%d\n",sizeof(ch2),strlen(ch2));
    // printf("%d\t%d\n",sizeof(ch3),strlen(ch3));
    // char  *ch4="abcd";
    // printf("%d\t%d\n",sizeof(ch4),strlen(ch4));
    // //sizeof(ch4) 计算的时指针变量

    // char  ch1[]="12345";
    // int  len=define_strlen(ch1);
    // printf("%d\n",len);
    // len=define_strlen("12345");
    // printf("%d\n",len);
    
    //字符数组赋值
    //char  ch1[]="abcd12321";
    //char  ch2[10];
    //char  ch2[10]="";
    //char  ch2[10]={'\0'};
    //bzero(ch2,sizeof(ch2));
    //memset(ch2,0,sizeof(ch2));

    //ch2=ch1;//错误
    //strcpy(ch2,ch1);//把ch1元素值赋值给ch2数组
    //define_strcpy(ch2,ch1);
    //strncpy(ch2,ch1,5);//复制前n字符
    //define_strncpy(ch2,ch1,0);
    //printf("%s\n",ch2);
    //strcpy(ch3,strcpy(ch2,ch1));
    //char *  ptr_ch=define_strncpy2(ch2,ch1,6);
    //printf("%s\n",ptr_ch);

    // char  ch1[]="abcd12321";
    // char  *ch2;
    // define_strncpy(ch2,ch1,0);//错误,ch2是一个野指针,为指向
    // printf("%s\n",ch2);

    // char  ch1[]="123456789";
    // char  ch2[5];  //ch2  ch1 存储在局部栈,ch2地址小于ch1
    // char  ch2[5];
    // char  ch1[]="123456789";   
    strcpy(ch2,ch1);
    printf("%s\n",ch2);
    printf("%s\n",ch1);
    return  0;
}