#include <stdio.h>  //加载头文件
/*
本文件中调用c 标准库函数,必须加载头文件声明
*/
/*代码存储在window系统D:\winshare
  使用虚拟机共享设置,把windows文件共享于linux
  编译使用linux gcc 编译器
  linux  访问 windows共享目录:
  [root@localhost ~]# cd   /mnt/hgfs/winshare/  //winshare根据本电脑设置共享文件夹名
  [root@localhost winshare]# cd L171001QC/
  */
/*
 任何c文件中必须有且只能存在一个主函数,为入口函数
 int argc,const char* argv[]称为主函数命令行参数
 [root@localhost L171001QC]# ./a.out 12232 sefe dfdsf

 int argc:参数个数,执行文件名算一个参数 argc>=1
 const char* argv[]:数组,存储参数值
*/
int main(int argc,const char* argv[])//主函数
{
    //printf("hello world\n");//标准输出函数
    if(argc>=1)
    {
        int i;
        for(i=0;i<argc;i++)
        {
            printf("%s\n",argv[i]);//"%s"表示输出多个字符(字符数组)
        }
    }
    return 0;//返回值
}
/*
如何编译
[root@localhost L171001QC]# gcc  hello.c  //默认生成一个文件  a.out
[root@localhost L171001QC]# ./a.out

[root@localhost L171001QC]# gcc   hello.c -o hello  //-o 制定可执行文件名
[root@localhost L171001QC]# ./hello
*/
