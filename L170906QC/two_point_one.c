#include <stdio.h>
/*
二级指针:指向指针的指针.指针存指向空间存储是另一个空间的地址
*/
int main(int argc,const char* argv[])
{
    //char* *  ptr;
    // printf("%d\n",sizeof(ptr));
    // printf("%d\n",sizeof(*ptr));
    // printf("%d\n",sizeof(**ptr));

    int **ptr=NULL;
    int *p=NULL;
    int data=200;
  
    ptr=&p;  p=&data;
    printf("%d\n",**ptr);
    return 0;
}