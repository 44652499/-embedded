#include <iostream>
using namespace std;
/*
将你需要的接口转换成你所拥有的接口,就是你不用改变你现在所拥有的接口,保证你在任何地方的用法都不需要修改,然后底层的实现由适配器调用需要的接口来具体实现
优点
1.屏蔽了具体的实现方式,实现了依赖倒转.
2.可以把不统一的接口封装起来,使之成为统一的接口.
3.把本来不方便适用的接口转换成统一的接口.
*/
class  target
{
	virtual  void  request()=0;
};

class adapter :public  target
{
public:
	adapter()
	{
		ptr=new adaptee();
	}
	void  request()
	{
		ptr->specificRequest();
	}
private:
	adaptee  *  ptr;
};

class  adaptee
{
public:
	void  specificRequest()
	{
		cout<<"specificRequest"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	target *tar=new  adapter();
	tar->request();
	return 0;
}