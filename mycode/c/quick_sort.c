int kssort(int a[],int left,int right)
{
   int tmp=a[left];
   while(left<right)
   {
   	  while(a[right]>tmp && left<right)
   	  {
   	  	right--;
   	  }
   	  if(left<right)
   	  {
   	  	a[left]=a[right];
   	  	left++;
   	  }

   	  while(a[left]<tmp && left<right)
   	  {
   	  	 left++;
   	  }
   	  if(left<right)
   	  {
   	  	  a[right]=a[left];
   	  	  right--;
   	  }
   }
   a[left]=tmp;
   return left;
}

void  quicksort(int a[],int left,int right)
{
    if(left<right)
    {
    	int pos=kssort(a,left,right);
    	quicksort(a,left,pos-1);
    	quicksort(a,pos+1,right);
    }	
}

int main(int argc, char const *argv[])
{
	int a[]={9,7,2,1,3,5,6};
	//mpsort(a,7);
	//jhsort(a,7);	
	//xzsort(a,7);
	//crsort(a,7);
	//jssort(a,7);
	//savedata(a,7);
	//getdata(5);
	int i;
	quicksort(a,0,6);
	for(i=0;i<7;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}