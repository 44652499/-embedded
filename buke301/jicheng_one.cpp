#include <iostream>
using namespace std;
/*
继承:面向对象编程中派生类直接使用基类的代码.主要是提高
代码重复利用率(拿来主义),提高开发效率
派生类继承基类:派生类的对象可以直接调用基类的方法.
派生类访问调用基类的方法与下面几个有关系:
1.继承方式
2.基类方法访问的权限有关
继承方式:
1.private:私有 默认此方式.基类私有成员不能继承,
               public,protected成员能继承在派生类作为private

2.public:公有继承  基类私有成员不能继承
         public,protected成员能继承在派生类作为 public,protected
3.protected：保护继承，基类私有成员不能继承
             public,protected成员能继承在派生类作为protected
*/
class base
{
public:
	void  fun()
	{
		cout<<"base fun"<<endl;
	}
};
//class child :  base
//class child :  public base
class child :  protected base
{
friend int main(int argc, char const *argv[]);
};

int main(int argc, char const *argv[])
{
	child c;
	c.fun();
	return 0;
}