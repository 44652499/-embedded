/*
 *Copyright 2009,ASC merger sort
 *All right reserved
 *文件名称: multithread.cpp
 *作者：杨洁
 *邮箱：evilyn.yangj@alibaba-inc.com
 *功能：用多线程实现对4G文本的排序,采用内排序(快速排序)和归并排序方法
 *当前版本：1.0
 */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
using namespace std;
long sizeBlock=0;//存储每个文件的行数
/*
 *功能 ：dealFile用于实现对原始文件进行分块
 *参数：，argv1存储要处理的文件名,sizeBlock存储每块大小
*/

int  dealFile(char *argv1,long sizeBlock)
{
	FILE *fp=fopen(argv1,"rt");
	int fileNum=1;//存储文件块数
	if(fp==NULL)
	{
		cerr<<"原始文件打开失败"<<endl;
		return 0;
	}//if
	FILE *fpSub=fopen("testdata\/0.txt","wt");
	if(fpSub==NULL)
	{
		cerr<<"文件打开失败！！"<<endl;
		return 0;
	}
	char content[256];
	int pos=1;//存储文件的一行分在的块号
	long count=0;//控制块大小
	char str[10];
	char fileName[20]="testdata\/";
	while(fgets(content,256,fp)!=NULL)
	{
		
		fgets(content,256,fp);
		fputs(content,fpSub);
		count++;
		if(count==sizeBlock)
		{
			count=0;
			pos++;
			if(str[0]!='\0')
				memset(str,'\0',20);
			fclose(fpSub);
			sprintf(str,"%d",pos);
			strcat(str,".txt");
			strcat(fileName,str);
            		fileNum++;
			fpSub=fopen(fileName,"wt");
			if(fpSub==NULL)
			{
				cerr<<"打开文件失败"<<endl;
				return 0;
			}
			memset(fileName,'\0',20);
			strcpy(fileName,"testdata\/");
		}//if		
		memset(content,'\0',256);
	}//while
	if(fpSub)
		fclose(fpSub);
	fclose(fp);
	return fileNum;
	
}//dealFile

////////////////////////////////////////////////////
//快速排序来实现对每个块排序
/////////////////////////////////////////////////////
int partition(char *p[],long low,long high)
{
	char *pivotkey=new char[256];
	strcpy(pivotkey,p[low]);
	while(low<high)
	{
		while(low<high && strcmp(p[high],pivotkey)>=0)
			--high;
		strcpy(p[low],p[high]);
		while(low<high && strcmp(p[low],pivotkey)<=0)
			++low;
		strcpy(p[high],p[low]);
	}//while
	strcpy(p[low],pivotkey);
	return low;
}
void qSort(char *p[],long low,long high)
{
	if(low<high)
	{
		long pivotloc=partition(p,low,high);
		qSort(p,low,pivotloc-1);
		qSort(p,pivotloc+1,high);
	}
}

void  * quickSort( void *arg)//对第arg进行快速排序
{
//	unsigned int blockNum=*((unsigned int *) arg);
	char fileName[20];
	strcpy(fileName,(char *)arg);
	FILE *fp=fopen(fileName,"rt");
	if(fp==NULL)
	{
		cerr<<"文件打开失败";
		return NULL;
	}
	char **p=new char *[sizeBlock];
	char content[256];
	long i=0;
	while(fgets(content,256,fp)!=NULL)
	{
		
		fgets(content,256,fp);
		p[i]=new char [256];
		strcpy(p[i++],content);	
		memset(content,'\0',256);	
	}
	fclose(fp);
	long sizeBlockNow=i+1;
	qSort(p,0,sizeBlockNow);
	fp=fopen(fileName,"wt");
	if(fp==NULL)
	{
		cerr<<"排序结果文件打开失败";
		return NULL;
	}
	for(long i=0;i <sizeBlockNow; i++)
		fputs(p[i],fp);	
	fclose(fp);
	for(long i=0;i<sizeBlockNow;i++)
		delete []p[i];
	delete []p;
}
//////////////////////////////////////////////////////
//堆排序的实现
//////////////////////////////////////////////////////////

struct Node//存储最大堆中的节点
{
	char *key;
	int num;//文件编号
	Node():key(NULL),num(0){}
	Node(const char *key,const int num)
	{
		this->key=new char[strlen(key)+1];
		strcpy(this->key,key);
		this->num=num;
	}
	~Node()
	{
		delete []key;
	}
};
/////////////////////////////////////////////////////////////
//调整堆,堆中第一个节点除外的其他节点都满足最小堆要求
/////////////////////////////////////////////////////////////
void heapAdjust(Node *heap1[],int s,int size)
{
	heap1[0]=new Node(heap1[s]->key,heap1[s]->num);
	for(int j=2*s; j<=size; j*=2)
	{
		if(j<size && strcmp(heap1[j]->key,heap1[j+1]->key)>0)
			++j;
		if(strcmp(heap1[0]->key,heap1[j]->key)<0)
			break;
		strcpy(heap1[s]->key,heap1[j]->key);
		heap1[s]->num=heap1[j]->num;
		s=j;
	}
	strcpy(heap1[s]->key,heap1[0]->key);
	heap1[s]->num=heap1[0]->num;
}
void heapSort(int numBlock)
{//numBlock为堆的节点个数，即为原来的文件块数
	Node **heap1=new Node *[numBlock+1];//第0个节点暂时不用
	for(int i=0;i<numBlock+1;i++)
	{
		heap1[i]=new Node;
		if(heap1[i]==NULL)
		{
			cerr<<"内存分配失败";
			return ;
		}
	}
	char *contentFile=new char[256];//存储文件内容
	FILE *fp[numBlock];
	char str[10];
	char fileName[20];
	for(int i=0;i< numBlock;i++)
	{//打开多个文件
		if(str[0]!='\0')
			memset(str,'\0',10);
		sprintf(str,"%d",i);
		strcat(str,".txt");
		if(fileName[0]!='\0')
			memset(fileName,'\0',20);
		strcpy(fileName,"testdata\/");
		strcat(fileName,str);
		fp[i]=fopen(fileName,"rt");
		if(fp[i]==NULL)
		{
			cerr<<"打开文件失败"<<endl;
			return ;
		}
	}//for
	FILE *result=fopen("resultSort.txt","wt");//存放排序结果
	if(result==NULL)
	{
		cerr<<"结果文件打开失败";
		return ;
	}
	for(int i=0; i< numBlock;i++)//将每个块的第一行存入堆的数组结构中
	{
		if(contentFile[0]!='\0')
			memset(contentFile,'\0',256);
		fgets(contentFile,256,fp[i]);
		heap1[i+1]=new Node(contentFile,i);
	}//节点存放在heap1[1--numBlock1]
	/*cout<<"输出堆的初始元素"<<endl;
	for(int i=0;i<numBlock;i++)
		cout<<heap1[i+1]->key<<endl;
	for(int i=numBlock/2;i >0;--i)//调整heap1[1--a]为最大堆
		heapAdjust(heap1,i,numBlock);
	cout<<"输出堆第一次调整后的结果"<<endl;
	for(int i=0;i<numBlock;i++)
		cout<<heap1[i+1]->key<<endl;*/
	cout<<"建堆成功"<<endl;
	char *change=new char [256];//用于堆中节点的交换
	int nodeNum;//存储堆中节点中的文件编号
	int size=numBlock;//堆中现有的节点个数，当某一个文件读完时，则堆的节点减少一个
	while(size>1)//堆中还存有数据
	{
		if(change[0]!='\0')
			memset(change,'\0',256);
		//交换第一个节点和最后一个节点的数据
		strcpy(change,heap1[1]->key);
		strcpy(heap1[1]->key,heap1[size]->key);
		strcpy(heap1[size]->key,change);
		nodeNum=heap1[1]->num;
		heap1[1]->num=heap1[size]->num;
		heap1[size]->num=nodeNum;
		fputs(heap1[size]->key,result);
		if(!feof(fp[heap1[size]->num]))//要读取的文件没有结束
		{
			if(contentFile[0]!='\0')
				memset(contentFile,'\0',256);
			fgets(contentFile,256,fp[heap1[size]->num]);
			strcpy(heap1[size]->key,contentFile);
			heapAdjust(heap1,1,size);
		}
		else
		{
			fclose(fp[heap1[size]->num]);
			delete heap1[size];
			size--;
			if(size==1)
				break;
			heapAdjust(heap1,1,size);
		}
	}//while
	cout<<"堆排序结束"<<endl;
	delete heap1[0];
	delete []change;
	delete []contentFile;
	delete []heap1;
	change=NULL;
	contentFile=NULL;
	heap1=NULL;
	fclose(result);
}


int main(int argc,char *argv[])
{
//argv[1]存储要处理的文件名,argv[2]存储块的大小
	if(argc!=3)
	{
		cerr<<"参数输入错误，第一个参数输要处理的文件名，第二个参数为每块大小"<<endl;
		return 1;
	}
	sizeBlock=(long)atol(argv[2]);
	int fileNum=dealFile(argv[1],sizeBlock);//对文件进行分块，各子文件存入testdata/文件夹下
	if(fileNum==0)
		return 1;
//用多线程对每一个文本块进行内排序，采用快速排序方法
	cout<<"文件分割完成"<<endl;
	int err;
	pthread_t idThread[fileNum];
	FILE *fp;
	int count=0;
	 char **fileName=new char *[fileNum];
	char str[10];
	char medFileName[20];
	for(int i=0;i<fileNum;i++)//存储分割内排序后文件名
	{
		fileName[i]=new char [20];
		if(str[0]!='\0')
			memset(str,'\0',10);
		sprintf(str,"%d",fileNum);
		strcat(str,".txt");
		if(medFileName[0]!='\0')
			memset(medFileName,'\0',20);
		strcpy(medFileName,"testdata\/");
		strcat(medFileName,str);
		strcpy(fileName[i],medFileName);
		
		
	}
	void *tret;
	for(int blockNum = 0; blockNum <fileNum;blockNum++)
	{
			err=pthread_create(&idThread[blockNum],NULL,quickSort,(void *)fileName[blockNum]);
			if(err!=0)
			{
				cerr<<"can't create thread"<<endl;
				return 1;
			}
	}//for
//结束线程，释放资源
	for(int blockNum = 0; blockNum <fileNum; blockNum++)
	{
		err=pthread_join(idThread[blockNum],NULL);
		if(err!=0)
		{
			cerr<<"create pthread error"<<endl;
			return 1;
		}
	}//for

	for(int i=0;i<fileNum;i++)
			delete []fileName[i];
	delete[]fileName;
//将快速排序后的每个块输出到文件,然后采用归并排序来实现整体有序
	cout<<"内排序结束"<<endl;
	heapSort(fileNum);
	return 0;
}
