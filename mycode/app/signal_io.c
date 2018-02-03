#include "define_header_file.h"
void fun(int sig_no)
{
    printf("SIGIO DOING\n");
}
int main(int argc,const char* argv[])
{
    signal(SIGIO,fun);
    printf("ending \n");
    return 0;
}