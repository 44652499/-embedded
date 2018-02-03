#include <iostream>
using namespace std;
/*
定义位图类
*/
class  bit_map
{
private:
	unsigned char *  bit_map_ptr;
	int start;
	int size;
public:
	bit_map(){}
	void bit_map_init(int _size,int _start)
	{
       bit_map_ptr=new unsigned char[_size];
       if(bit_map_ptr==NULL)
       		return;
       start=_start;
       size=_size;
       bzero(bit_map_ptr,size);
	}

	int  bit_map_set(int value)
	{
		int pos=(value-start)/8;
		int re_pos=(value-start)%8;
		unsigned char ch=0x1<<re_pos;
		if(pos>size)
			return 0;
		bit_map_ptr[pos]|=ch;
		return 1;
	}

	int  bit_map_get(int index)
	{
		int pos=index/8;
		int re_pos=index%8;
		unsigned char ch=0x1<<re_pos;
		unsigned char result;
		if(pos>size)
			return 0;
		result=bit_map_ptr[pos]&ch;
		return result>0?1:0;
	}

	int  bit_map_get_data(int index)
	{
		return index+start;
	}
	~bit_map()
	{
		if(bit_map_ptr!=NULL)
		{
			delete[]  bit_map_ptr;
			bit_map_ptr=NULL;
		}
	}
};
/*
获取目标数组中的最大元素 
*/
int get_max_data(int * array,int size)
{
	int i;
	int max=array[0];
	for(i=0;i<20;i++)
	{
		cout<<array[i]<<"\t";
	}
	cout<<endl;
	for(i=0;i<size;i++)
	{
       if(array[i]>max)
       {
       		max=array[i];
       }
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int array[] = {5,8,7,6,3,1,10,78,56,34,23,12,43,54,65,76,87,98,89,100};	
    int i;
    bit_map  bmap1;
    int max_data=get_max_data(array,20);
    int block_num=max_data%8?max_data/8+1:max_data/8;
    bmap1.bit_map_init(block_num,0);
    for(i=0;i<20;i++)
    {
    	bmap1.bit_map_set(array[i]);
    }
    for(i=0;i<max_data;i++)
    {
    	if(bmap1.bit_map_get(i)>0)
    	{
    		cout<<bmap1.bit_map_get_data(i)<<"\t";
    	}
    }
    cout<<endl;
	return 0;
}