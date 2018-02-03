#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
int main()
{
  fd_set ff;
  printf("%d\n",sizeof(ff));
  return 0;
}
