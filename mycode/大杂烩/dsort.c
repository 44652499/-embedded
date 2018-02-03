#include<stdio.h>
#include<stdlib.h>
void min_heapfy(int a[],int HEAPSIZE,int i)
{
	int t;
    int flag=1;
    int j=2*i; //���ӽ��
    t=a[i]; //�ݴ����¼
    while(j<=HEAPSIZE&&flag)
    {     
        if((j+1)<=HEAPSIZE&&a[j]<a[j+1])     j++; //�������������������������Ĺؼ��ִ������ҷ�֧"ɸѡ"
        if(t>=a[j]) 
			flag=0; //ɸѡ���
        else
        {
            a[i]=a[j];
            i=j;
            j=2*i;
        } //����ɸѡ
    }
    a[i]=t; //��a[i]����ǡ����λ��
}

void Create_min_heap(int a[],int length)//������
{    
    int i;
    for(i=length/2;i>=1;i--)/*�Ե�[length/2]����¼��ʼ����ɸѡ����*/
       min_heapfy(a,length,i);
}

/*��a[1....n]���ж�����ִ�б��㷨��a[]�м�¼���ؼ����ɴ�С����*/
void HeapSort(int a[],int length)
{
    int i,e;
    Create_min_heap(a,length); 
    for(i=length;i>=1;--i)
    {
        printf("%4d",a[1]); //����Ѷ�
        e=a[1];                //���Ѷ���¼�Ͷ��е����һ����¼���н���
        a[1]=a[i];
        a[i]=e;
        min_heapfy(a,i-1,1); //���е�����ʹa[1....n-1]��¼��ɶ�
    }
}

int main()
{
    int a[100];
    int i;
    int length;    
    printf("������Ԫ�ظ��� : ");
    scanf("%d",&length);    
    for(i=1;i<=length;i++)
        scanf("%d",&a[i]);        
    printf("\n");
    Create_min_heap(a,length);
    printf("�����ö��Ժ������Ԫ��������ʾ: \n");
    for(i=1;i<=length;i++)
        printf("%4d",a[i]);
    printf("\n");
    printf("���������Ķ�,����Ԫ��������ʾ : \n");
    HeapSort(a,8);    
    printf("\n");

    
}
