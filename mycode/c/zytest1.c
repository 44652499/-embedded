#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// char *c[] = {"ENTER","NEW","POINT","FIRST"};  
// char **cp[] = { c + 3 , c + 2 , c + 1 , c};  
// char ***cpp = cp;  
// int main(void)  
// {  
//  printf("%s",**++cpp);  
//  printf("%s",*--*++cpp+3);  
//  printf("%s",*cpp[-2]+3);  
//  printf("%s\n",cpp[-1][-1]+1); 
//  return 0;  
// }

// int main(int argc, char const *argv[])
// {
// 	// int s[6][2]={1,2,3,4,5,6,7,8,9};
//  //    int *p=s[1];
//  //    int (*q)[2]=&s[1];
//  //    printf("%d",*p++);
//  //    printf("%d",*++p);
//  //    printf("%d",q[0][0]);
//  //    printf("%d",q[3][2]);
// 	return 0;
// }
// #include <string.h>
// #define MAX_LEN 1024
// void   loopMove(char *pstr,int n)
// {
// 	int num=strlen(pstr)-n;
// 	char tmp[MAX_LEN];
// 	strcpy(tmp,pstr+num);
// 	strcpy(tmp+n,pstr);
// 	*(tmp+strlen(pstr))='\0';
// 	strcpy(pstr,tmp);
// }

// char  tmp[MAX_LEN];
// void substr(char* pstr,int index,int len)
// {
// 	char  t[MAX_LEN];
// 	strcpy(t,pstr);
// 	int str_len=strlen(t);
// 	if(index+len<=str_len)
// 	{
// 		*(t+index+len)='\0';
//         strcpy(tmp,t+index);
// 	}    
// }

// int  find(char* pstr,char* cstr)
// {
// 	int index=0;
// 	char * tmp=cstr;
// 	int isexists=1;
// 	while(*tmp!='\0')
// 	{
// 		isexists=1;
//         while(*pstr!=*tmp)
//         {
//         	if(*pstr=='\0')
//         		return -1;
//         	pstr++;
//         	index++;
//         	tmp=cstr;
//         	isexists=0;
//         }
//         if(isexists==1)
//         {
//         	tmp++;
//             pstr++;
//         }        
// 	}
// 	return index;
// }

// void  find_max_str(char *pstr)
// {
// 	int i,j;
// 	int len=strlen(pstr);
// 	for(i=len-1;i>1;i--)
// 	{
// 		for(j=0;j<len;j++)
// 		{
// 			if(j+i<=len)
// 			{
// 				int t=0;
// 				int num=0;
// 				bzero(tmp,sizeof(tmp));
// 				substr(pstr,j,i);
// 				t=find(pstr,tmp);
// 				if(t>0)
// 				{
// 					num=find(pstr+t+strlen(tmp),tmp);
// 					if(num>0)
// 					{
// 						printf("tmp=%s\tt=%d\tnum=%d\n",tmp,t,t+strlen(tmp)+num);
// 						return ;
// 					}
// 				}
// 			}
// 		}
// 	}
// }

// // void  get_sub_str(char *pstr)
// // {
// // 	int i,j;
// // 	int len=strlen(pstr);
// // 	for(i=len-1;i>1;i--)
// // 	{
// // 		for(j=0;j<len;j++)
// // 		{	
// // 	        if(j+i<=len)
// // 	        {
// // 	        	printf("i=%d\tj=%d\n",i,j);
// // 	        	bzero(tmp,sizeof(tmp));		
// // 		        substr(pstr,j,i);
// // 		        //printf("tmp=%s\n",tmp); 
// // 	        }		
// // 		}
// // 	}
// // }
// int main(int argc, char const *argv[])
// {
// 	char ch[]="abcdefgcd12";
// 	//loopMove(ch,6);
// 	//bzero(tmp,sizeof(tmp));
// 	//substr(ch,6,1);
// 	//printf("%s\n",tmp);
// 	// int index=find(ch,"abcd");
// 	// printf("%d\n",index);
// 	// index=rfind(ch,"abcd");
// 	// printf("%d\n",index);
// 	//find_max_str(ch);
// 	 // find_max_str(ch);
// 	unsigned char i=0x80; 
//     printf("0x%x\n", ~i>>3+1);
// 	return 0;
// }

// char *GetMemory()
// {
//   char* p="hello world";
//   return p;
// }
// void Test(void)
// {
//   char *str = NULL;
//   str = GetMemory();
//   printf("%s\n",str);
// }
// int main(int argc, char const *argv[])
// {
// 	Test();
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	char ch_data1[100];
	char ch_data2[100];
	gets(ch_data1);
	gets(ch_data2);
	int ch_len1=strlen(ch_data1);
	int ch_len2=strlen(ch_data2);
	int ch_len=(ch_len1>ch_len2?ch_len2:ch_len1)+2;
	printf("%d\n",ch_len);
	char* ch_result=(char*)malloc(ch_len*sizeof(char));
	if(ch_result==NULL)
	{
		printf("malloc fail\n");
		return;
	}
	bzero(ch_result,sizeof(ch_result));
    int index_ch1=ch_len1-1,index_ch2=ch_len2-1,index_result=ch_len-1;
    int tmp;
    while(1)
    {
    	tmp=ch_data1[index_ch1]-'0'+ch_data2[index_ch2]-'0';
    	if(ch_result[index_result]!='\0')
    	   tmp=tmp+ch_result[index_result]-'0';
    	else
    		tmp=tmp+ch_result[index_result];
    	if(tmp>=10)
    	{
    		ch_result[index_result-1]=tmp/10+'0';
    		tmp=tmp%10;
    	}
    	ch_result[index_result]=tmp+'0';
    	index_ch1--;
    	index_ch2--;
    	index_result--;
    	if(index_ch2<0 && index_ch1<0)
    	{
    		break;
    	}
    	if(index_ch1<0 && index_ch2>=0)
    	{
    		while(index_ch2>=0)
    		{
    			if(ch_result[index_result]!='\0')
    			{
    				ch_result[index_result--]=ch_result[index_result]-'0'+ch_data2[index_ch2--];
    			}
    			else
    			{
    				ch_result[index_result--]=ch_data2[index_ch2--];
    			}
    		 
    		}
    		break;
    	}
    	if(index_ch2<0 && index_ch1>=0)
    	{
    		while(index_ch1>=0)
    		{
    			if(ch_result[index_result]!='\0')
    			   ch_result[index_result--]=ch_result[index_result]-'0'+ch_data1[index_ch1--];
    			else
    				 ch_result[index_result--]=ch_data1[index_ch1--];
    		}   
    		break;         
    	}    	
    }

    int i=0;
    for(i=0;i<ch_len;i++)
    {
    	printf("%c",ch_result[i]);
    }
    printf("\n");
	return 0;
}