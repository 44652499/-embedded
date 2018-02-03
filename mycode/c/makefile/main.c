#include <stdio.h>
#include "add.h"
#include "sub.h"
int main(int argc,const char* argv[])
{
    int a=5,b=6;
    printf("%d\n",add(a,b));
    printf("%d\n",sub(a,b));
    return 0;
}