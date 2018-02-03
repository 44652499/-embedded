#include "definefile.h"
void readdirs(char * dirname)
{
      DIR * dir=opendir(dirname);
      if(dir==NULL)
      {
            perror("opendir:");
            exit(-1);
      }
      chdir(dirname);
      struct dirent* ent=readdir(dir);
      struct stat st;
      while(1)
      {
            if(ent==NULL)
 			break;
 		stat(ent->d_name,&st);
            if(S_ISDIR(st.st_mode))
		{
			if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)
			{
				ent=readdir(dir);
				continue;
			}
			printf("%s\n",ent->d_name);
			readdirs(ent->d_name);//µİ¹éËÑË÷Ä¿Â¼
		}
            else
            {
                  printf("\t%s\n",ent->d_name);
            }
            ent=readdir(dir);
      }
      chdir("..");
}
int main(int argc, char const *argv[])
{
      readdirs("A");
      return 0;
}
