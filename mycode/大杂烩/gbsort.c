#include <stdio.h>
void Merge(int array[],int start,int mid,int end)
{
	int temp1[10],tmp2[10];
	int n1,n2;
	n1=mid-start+1;
	n2=end-mid;

	int i,j;
	for(i=0;i<n1;i++)
	{
		temp1[i]=array[start+i];
	}

	for(i=0;i<n2;i++)
	{
		temp2[i]=array[mid+i+1];
	}
	temp1[n1]=temp2[n2]=1000;
	int k;
	for(k=start,i=0,j=0;k<end;k++)
	{
       if(temp1[i]<=temp2[j])
	   {
		   array[k]=temp1[i];
		   i++;
	   }
	   else
	   {
		   array[k]=temp2[j];
		   j++;
	   }
	}
}

void MergeSort(int array[],int start,int end)
{
	if(start<end)
	{
		int i;
		i=(end+start)/2;
		MergeSort(array,start,i);
        MergeSort(array,i+1,end);
        Merge(array,start,i,end);
	}
}
int main(int argc, char *argv[])
{
   int array[]={ 2,5,56,1,78,6,55,3,8,9,123,258,4568 };
   MergeSort(array, 0,sizeof(array)/sizeof(array[0]));
   int i;
   for(i=0;i<sizeof(array)/sizeof(array[0]);i++)
   {
	   printf("%d\t",array[i]);
   }
   printf("\n");
   return 0;
}
