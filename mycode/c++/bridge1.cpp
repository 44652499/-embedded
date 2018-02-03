#include <iostream>
using namespace std;
/*
将抽象化(Abstraction)与实现化(Implementation)分离,使得二者可以独立地变化
常用的场景
1.当一个对象有多个变化因素的时候,考虑依赖于抽象的实现,而不是具体的实现.如上面例子中手机品牌有2种变化因素,一个是品牌,一个是功能.
2.当多个变化因素在多个对象间共享时,考虑将这部分变化的部分抽象出来再聚合/合成进来,如上面例子中的通讯录和游戏,其实是可以共享的.
3.当我们考虑一个对象的多个变化因素可以动态变化的时候,考虑使用桥接模式,如上面例子中的手机品牌是变化的,手机的功能也是变化的,所以将他们分离出来,独立的变化.
优点
1.将实现抽离出来,再实现抽象,使得对象的具体实现依赖于抽象,满足了依赖倒转原则.
2.将可以共享的变化部分,抽离出来,减少了代码的重复信息.
3.对象的具体实现可以更加灵活,可以满足多个因素变化的要求
*/
class Abstraction
{
 public:
 	virtual void operation()=0;
};
class DefinedAbstraction: public Abstraction
{
public:
	DefinedAbstraction(AbstractionImplement* _absImp)
	{
		absImp=_absImp;
	}
	void operation()
	{
		absImp->operation();
	}
private:
    AbstractionImplement* absImp;
};

class AbstractionImplement
{
public:
	virtual void operation() = 0;
};

class ConcreteAbstractionImplement1:public AbstractionImplement
{
public:
	void operation()
	{
		cout<<"ConcreteAbstractionImplement1 operation"<<endl;
	}
};

class ConcreteAbstractionImplement2:public AbstractionImplement
{
public:
	void operation()
	{
		cout<<"ConcreteAbstractionImplement2 operation"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	AbstractionImplement* absImp1 = new ConcreteAbstractionImplement1();
	Abstraction* abs1 = new DefinedAbstraction(absImp1);
	abs1->operation();
	AbstractionImplement* absImp2 = new ConcreteAbstractionImplement2();
	Abstraction* abs2 = new DefinedAbstraction(absImp2);
	abs2->operation();
	return 0;
}