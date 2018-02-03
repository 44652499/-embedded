#include <math.h>
#include <stdio.h>
int main(int argc ,const char* argv[])
{
    printf("%f\n",pow(3,2));
    return 0;
}
//[root@localhost L171101QC]# gcc  -lm pow_one.c //-l链接时制定lib 文件名首字母
//[root@localhost L171101QC]# gcc  -lpthread pow_one.c //-l链接时制定lib 文件名首字母
//[root@localhost L171101QC]# gcc  -lmysql pow_one.c //-l链接时制定lib 文件名首字母