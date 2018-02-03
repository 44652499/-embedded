int add(int a,int b)
{
    //extern int g_data;//外部引用声明
    //g_data=400;
    //extern int g_data=400;//错误,不能初始化.根本没有分配空间
    //extern int g_array[3];
    //extern int g_array[];//以上写法正确,引用数组时自需要获取数组首元素地址
    //extern int *  g_array;//引用一个数组必须按照数组方式引用,不能按指针方式引用
    printf("%X\n",&g_array);
    //return a+b+g_data;
    return a+b+g_array[1];//g_array[1]  等价于g_array+1
    //return a+b+*g_array;//错误
}