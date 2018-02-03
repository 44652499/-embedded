#include "definefile.h"
int main(int argc, char const *argv[])
{
      DIR * dir=opendir("A");
      if(dir==NULL)
      {
            perror("opendir:");
            exit(-1);
      }
      struct dirent* ent=readdir(dir);
      while(1)
      {
            printf("%s\n",ent->d_name);
            ent=readdir(dir);
            if(ent==NULL)
              break;
      }
      return 0;
}
