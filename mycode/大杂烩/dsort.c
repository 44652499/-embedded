#include<stdio.h>
#include<stdlib.h>
void min_heapfy(int a[],int HEAPSIZE,int i)
{
	int t;
    int flag=1;
    int j=2*i; //左孩子结点
    t=a[i]; //暂存根记录
    while(j<=HEAPSIZE&&flag)
    {     
        if((j+1)<=HEAPSIZE&&a[j]<a[j+1])     j++; //若存在右子树，且右子树根的关键字大，则沿右分支"筛选"
        if(t>=a[j]) 
			flag=0; //筛选完毕
        else
        {
            a[i]=a[j];
            i=j;
            j=2*i;
        } //继续筛选
    }
    a[i]=t; //将a[i]填入恰当的位置
}

void Create_min_heap(int a[],int length)//创建堆
{    
    int i;
    for(i=length/2;i>=1;i--)/*自第[length/2]个记录开始进行筛选建堆*/
       min_heapfy(a,length,i);
}

/*对a[1....n]进行堆排序，执行本算法后，a[]中记录按关键字由大到小排列*/
void HeapSort(int a[],int length)
{
    int i,e;
    Create_min_heap(a,length); 
    for(i=length;i>=1;--i)
    {
        printf("%4d",a[1]); //输出堆顶
        e=a[1];                //将堆顶记录和堆中的最后一个记录进行交换
        a[1]=a[i];
        a[i]=e;
        min_heapfy(a,i-1,1); //进行调整，使a[1....n-1]记录变成堆
    }
}

int main()
{
    int a[100];
    int i;
    int length;    
    printf("请输入元素个数 : ");
    scanf("%d",&length);    
    for(i=1;i<=length;i++)
        scanf("%d",&a[i]);        
    printf("\n");
    Create_min_heap(a,length);
    printf("创建好堆以后的数组元素如下所示: \n");
    for(i=1;i<=length;i++)
        printf("%4d",a[i]);
    printf("\n");
    printf("经过排序后的堆,数组元素如下所示 : \n");
    HeapSort(a,8);    
    printf("\n");

    
}
