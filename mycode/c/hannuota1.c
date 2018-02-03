#include <stdio.h>
/*
问题:
汉诺塔是根据一个传说形成的一个问题。汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘
算法:
当只有一个盘子的时候，只需要从将A塔上的一个盘子移到C塔上。
当A塔上有两个盘子是，先将A塔上的1号盘子（编号从上到下）移动到B塔上，再将A塔上的2号盘子移动的C塔上，最后将B塔上的小盘子移动到C塔上。
当A塔上有3个盘子时，先将A塔上编号1至2的盘子（共2个）移动到B塔上（需借助C塔），然后将A塔上的3号最大的盘子移动到C塔，最后将B塔上的两个盘子借助A塔移动到C塔上。
当A塔上有n个盘子是，先将A塔上编号1至n-1的盘子（共n-1个）移动到B塔上（借助C塔），然后将A塔上最大的n号盘子移动到C塔上，最后将B塔上的n-1个盘子借助A塔移动到C塔上
*/
int g_step=0;
void  move(int n,char from,char to)
{
        printf("the %d step:move %d pan %c ------>%c\n",g_step++,n,from,to);
}
void  hannuota(int n,char from,char denpend_on,char to)
{
        if(n==1)
        {
                move(1,from,to);
        }
        else
        {
                hannuota(n-1,from,to,denpend_on);
                move(n,from,to);
                hannuota(n-1,denpend_on,from,to);
        }
}
int main(int argc,const char argv[])
{
        int n;
        scanf("%d",&n);
        char x='A',y='B',z='C';
        hannuota(n,x,y,z);
        return 0;
}
