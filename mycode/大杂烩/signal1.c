#include <signal.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
    printf("%d\n",sizeof(sigset_t));
    return 0;
}
