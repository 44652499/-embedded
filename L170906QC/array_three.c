#include <stdio.h>
int main(int argc,const char* argv[])
{
    //1.定义一个数组,里面有10个元素,输出数组最大和最小元素值
    // int  array_one[10];
    // int i;
    // for(i=0;i<10;i++)
    // {
    //     scanf("%d",array_one+i);
    //     //scanf("%d",&array_one[i]);
    // }
    // int max=array_one[0];
    // int min=array_one[0];
    // for(i=1;i<10;i++)
    // {
    //     if(max<array_one[i])
    //     {
    //         max=array_one[i];
    //     }
    //     if(min>array_one[i])
    //     {
    //         min=array_one[i];
    //     }
    // }
    // printf("max=%d\tmin=%d\n",max,min);

    //2.13个人围成一圈,从第一个人开始报数1,如果报数是3的倍数出圈,请问最后剩下的人编号是多少?
    // int  array_one[13];
    // int i;
    // for(i=0;i<13;i++)
    // {
    //     array_one[i]=i+1;
    // }
    // int cnt=1;//数数
    // int index=0;//数组下标
    // int person_num=13;//记录剩下人数
    // while(1)
    // {
    //     //没有出队的人继续报数
    //     if(array_one[index]!=0)
    //     {
    //         if(cnt%3==0)
    //         {
    //             array_one[index]=0;//出队
    //             person_num--;//人数递减
    //             if(person_num==1)
    //             {
    //                 break;
    //             }
    //             cnt=1;
    //         }
    //         else
    //         {
    //             cnt++;
    //             index++;            
    //         }        
    //     } 
    //     else
    //     {
    //         index++;
    //     }   
    //     if(index==13)
    //     {
    //         index=0;
    //     }   
    // }

    // for(i=0;i<13;i++)
    // {
    //     if(array_one[i]!=0)
    //     {
    //         printf("%d\n",array_one[i]);
    //     }
    // }

    //定义个数组记录考试的分数([0,100]),有序输出成绩
    // int array_score[101]={0};
    // //随机数填充分数
    // int i;
    // srand(time(NULL));//设置随机函数种子
    // for(i=0;i<101;i++)
    // {
    //   // printf("%d\t",rand()%101);//产生随机数
    //   //array_score[i]=rand()%101;
    //   int index=rand()%101;
    //   array_score[index]=array_score[index]+1;
    // }
    // //输出数组
    // for(i=0;i<101;i++)
    // {
    //     while(array_score[i]!=0)
    //     {
    //         printf("%d\t",i);
    //         array_score[i]=array_score[i]-1;
    //     }
    // }
    //将一个一位数组a[10]中的元素值按逆序重新存放.假定数组中原来元素顺序为:1,3,5,7,9,8,6,4,2,0,按逆序重新存放后元素的值位:0,2,4,6,8,9,7,5,3,1。要求：在程序中将数组初值初始化，输出逆序重新存放后元素的值
    int array_one[]={1,3,5,7,9,8,6,4,2,0};
    int i;
    for(i=0;i<10/2;i++)
    {
        int tmp=array_one[i];
        array_one[i]=array_one[10-i-1];
        array_one[10-i-1]=tmp;
    }
    for(i=0;i<10;i++)
    {
        printf("%d\t",array_one[i]);
    }
    printf("\n");
    return 0;
}