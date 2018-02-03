#include  <stdio.h>
/*
有一个16位的无符号整数，每4位为一个数，写函数求他们的和
*/

void   zuoye_one()
{
	unsigned  short  data;
	scanf("%hu",&data);//"%hu" 无符号短整数格式
	//printf("%hu\n",data);
	int array[]={0,1,2,4,8};
	int index=1;
	unsigned int sum=0;
	while(data!=0)
	{
       unsigned  short tmp=data&0xf;
       data=data>>4;
       index=1;
       while(tmp!=0)
       {
       	 unsigned short tmp_two=tmp&0x1;
       	 if(tmp_two>0)
       	 {
       	 	sum+=array[index];
       	 }
       	 tmp=tmp>>1;
       	 index++;
       }
	}
	printf("sum=%u\n",sum);
}

/*写一个函数，对一个16位的二进制数取出他的奇数位*/
// 0011 0110  
void  zuoye_two()
{
	unsigned  short  data;
	scanf("%hu",&data);//"%hu" 无符号短整数格式
	int array[16];
	int index=0;
	while(data!=0)
	{

		if(data&0x1)
		{
			array[index]=1;
			//printf("1");
		}
		else
		{
			array[index]=0;
			//printf("0");
		}
		index++;
		data=data>>2;
	}

	while(--index>=0)
	{
		printf("%d",array[index]);
	}
	printf("\n");
}

/*利用位运算,实现数字转换(十进制转换成二进制)*/
void  zuoye_three()
{
	unsigned  short  data;
	scanf("%hu",&data);//"%hu" 无符号短整数格式
	int array[16];
	int index=0;
	while(data!=0)
	{
		if(data&0x1)
		{
			array[index++]=1;
		}
		else
		{
			array[index++]=0;
		}
		data=data>>1;
	}
	while(--index>=0)
	{
		printf("%d",array[index]);
	}
	printf("\n");
}
/*输一个无符号整数,请统计该数对应二进制中1的个数*/
void  zuoye_four()
{
	unsigned  int  data;
	scanf("%u",&data);
	int counter=0;
	while(data!=0)
	{
		if(data&0x1)
		{
			counter++;
		}
		data=data>>1;
	}
	printf("%d\n",counter);
}
int main(int argc, char const *argv[])
{
	//zuoye_two();
	//zuoye_three();
	//zuoye_four();

	int data=0x12345678;
	//通过位运算实现输出结果是：0x78563412
	//0x12 =  data&0xff000000
	//0x34 =  data&0x00ff0000
	//0x56 =  data&0x0000ff00
	//0x78 =  data&0x000000ff
	//合并: (data&0xff000000)>>24 || (data&0x00ff0000)>>8 ||(data&0x0000ff00)<<8 ||(data&0x000000ff)<<24
	data=(data&0xff000000)>>24 | (data&0xff0000)>>8 |(data&0xff00)<<8 |(data&0xff)<<24;
	printf("%X\n",data);
	return 0;
}
//100     0110 0100