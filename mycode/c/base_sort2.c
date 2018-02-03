#include <stdio.h>
#include <string.h>
/*
基本思想:按组成关键字的各个位的值来实现排序的
基数:计算的基数就是基本的单元数.比如10进制的基数就是10,二进制的基数就2,八进制的基数是8等等。
基数排序说通俗点,就是把带排序的N个数字右对齐排成一列.然后把相同的位数互相比较排序
*/
//获取最大数的位数
int  get_bit_nums(int *p,int size)
{
	int count;
	int temp[size];
	int i;
	int maxbit=0;
	for(i=0;i<size;i++) 
	{
		temp[i]=p[i];
	}

	for(i=0;i<size;i++)
	{
		count=0;
		while(temp[i]!=0)
		{
			count++;
			temp[i]=temp[i]/10;
		}
		if(maxbit<count)
			maxbit=count;
	}
	return maxbit;
}
//将数字分配到各自的桶中，然后按照桶的顺序输出排序结果
void  base_sort2(int *p,int n,int loop)
{
	//建立一组桶此处的20是预设的根据实际数情况修改
	int basearr[10][10];
	memset(basearr,-1,sizeof(basearr));
	//求桶的index的除数
    //如798个位桶index=(798/1)%10=8
    //十位桶index=(798/10)%10=9
    //百位桶index=(798/100)%10=7
    //tempNum为上式中的1、10、100
	int tempnum=1;
	while(--loop>0)
	{
		tempnum=tempnum*10;
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		int row_index=p[i]/tempnum%10;
		for(j=0;j<10;j++)
		{
			if(basearr[row_index][j]==-1)
			{
				basearr[row_index][j]=p[i];
				break;
			}
		}
	}
	//将桶中的数，倒回到原有数组中
	int k=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(basearr[i][j]!=-1)
			{
				p[k]=basearr[i][j];
				basearr[i][j]=-1;
				k++;
			}
		}
	}
}

//基数排序
void   base_sort(int * a_p,int size)
{
	//获取最大数的位数,次数也是再分配的次数.
	int count=get_bit_nums(a_p,size);
	int i;
	//对每一位进行桶分配
	for(i=1;i<=count;i++)
	{
		base_sort2(a_p,size,i);
	}
}




int main(int argc, char const *argv[])
{
	int a[]={2,343,342,1,123,43,4343,433,687,654,3};
	int *a_p=a;
	int size=sizeof(a)/sizeof(a[0]);
	base_sort(a_p,size);
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}