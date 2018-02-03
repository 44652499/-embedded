#include "appheader.h"
int main(int argc, char const *argv[])
{
	//system("sh readconfig.sh");
	FILE * fp=popen("sh readconfig.sh","r");
	if(fp==NULL)
	{
		perror("popen:");
		exit(-1);
	}
	char buf[1024];
	bzero(buf,sizeof(buf));
	fread(buf,sizeof(buf)-1,1,fp);
	//printf("%s",buf);
	char *p=buf;
	int counter=0;
	while(*p!='\0')
	{
		if(*p==' ')
		{
			*p='\0';
			counter++;
		}
		p++;
	}
	counter++;
	//printf("%d\n",counter);
	char**ipbuf=(char**)malloc(counter*sizeof(char*));
	int i;
	for(i=0;i<counter;i++)
	{
		ipbuf[i]=(char*)malloc(20*sizeof(char));
		//bzero(ipbuf[i],sizeof(ipbuf[i]));
	}
	p=buf;
	int len=strlen(p);
	i=0;
	while(len>0)
	{
		//printf("%s\n",p);
		strcpy(ipbuf[i],p);
		p=p+len+1;
		len=strlen(p);
		i++;
	}
	// printf("%s\n",ipbuf[0]);
	// printf("%s\n",ipbuf[1]);
	// printf("%s\n",ipbuf[2]);
	// printf("%s\n",ipbuf[3]);
	// printf("%s\n",ipbuf[4]);
	 for(i=0;i<5;i++)
	 {
	 	printf("%s\n",ipbuf[i]);
	 }
	return 0;
}