#include <stdio.h>  
void PrintArray(int b[],int n)  
{   
  int i;  
  for(i=0;i<n;i++)  
  printf("%d ", b[i]);  
  printf("\n");
}  
void CreateHeap(int b[], int i, int len)  
{  
  int temp,j;  
  /*当前结点看作一个父结点，先把它的值存储到临时变量， 
  *防止交换过程中父亲结点的值被覆盖掉 
  */  
  temp = b[i];  
  for(j=2*i+1;j<len;j=2*j+1)  
  {  
    /*如果左孩子(a[j])比右孩子(a[j+1])小 
     *就比较右孩子和父亲结点a[i] 
     *否则就比较左孩子和父亲结 
     */  
    if(j<len-1 && b[j]<b[j+1])  
    {  
      ++j;  
    }  
    if(temp>=b[j])  
    {  
      break;  
    }  
     /*父结点比孩子结点小，把较大的孩子结点值赋给父亲结点 
      *并记住较大的孩子结点下标 
      */  
    b[i]=b[j];  
     /*如果循环不结束，下次将以这次下标为j的元素为父结点和这个父结点的左右子元素比较 
      *如果循环比较结束，循环最外层将会把父亲结点的最小值赋给子结点中最大 
      */  
    i=j;  
   }  
   /*此处其实是把父结点的旧值赋给值最大的那先前子结点*/  
   b[i]=temp;  
}  
void InitHeap(int a[],int arr_len)  
{  
  int i;  
  for(i=(arr_len-1)/2;i>=0;i--)  
  {  
    CreateHeap(a, i, arr_len);  
  }  
}  
void HeapSort(int a[],int arr_len)  
{  
  InitHeap(a, arr_len);  
  printf("初始最大堆：");  
  PrintArray(a, arr_len);  
  printf("\n");  
  int i,temp;  
  for(i=arr_len-1;i>0;i--)  
  {  
    temp = a[i];  
    a[i] = a[0];  
    a[0] = temp;  
    /*从根结点(0代表从根结点，原始最大堆末尾原素现在变成第一个元素) 
     *上开始逐次往下调整堆为最大堆 
     *每次从最大堆换到末尾的那个元素，下次调整时不算在内，所以用递减的i 
     *当最后剩一个a[0]为结点时就没必要再调整了，此时a[0]就是最小的 
     */  
     printf("第%d次堆排序结果：",(arr_len-i));  
     CreateHeap(a, 0, i);  
     PrintArray(a, arr_len);  
     printf("\n");  
   }  
}  
int main()  
{  
  int a[]={10,50,32,5,76,9,40,88};  
  int arr_len = sizeof(a)/sizeof(a[0]);  
  HeapSort(a, arr_len);  
  printf("堆排序的最终结果:");  
  PrintArray(a, arr_len);  
  return 0;  
}  