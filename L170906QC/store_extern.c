int  add_int(int a,int b)
{
	//int g_idata=30;//重新定义局部变量
	//extern int g_idata;//外部引用声明
	//g_idata=300;

	//extern int g_idata=300;//错误, 不能对外部引用变量初始化

	//extern int g_idata;//语法正确,但是结果错误.外部引用时与全局定义一样(数据类型)

	//extern  int  g_array[];//引用外部数组
	//extern  int  g_array[3];//引用外部数组
	//return a+b+g_idata; 
	extern int *  g_array;//错误,引用的是一个全局数组,不能用指针形式引用
	g_array[0]=10;
	return a+b+g_array[0];
}