#include "definefile.h"
int main(int argc, char const *argv[]) {
    int counter;
    alarm(1);//Ĭ�����˳�
    for(counter=0;1;counter++)
    {
        printf("%d\t",counter);
    }
    return 0;
}
