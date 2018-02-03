#include  <iostream>
using namespace std;
/*
继承:子类继承父类,子类的对象可以直接访问父类公有或保护成员
继承最大特点提高代码重用,也体现代码的共性与个性
派生类:继承父类的子类
基类:被继承类(父类)
继承语法:
派生类 : [继承方式] 基类 

继承方式:
1.private:私有继承.默认为此继承方式.不能继承基类的私有成员.继承基类公有成员,在派生类中相当于是私有成员.继承基类保护成员,在派生类中相当于是私有成员
2.public:公有继承.不能继承基类的私有成员.继承基类公有成员,在派生类中相当于是公有成员.继承基类保护成员,在派生类中相当于是公有成员
3.protected:保护继承,不能继承基类的私有成员.继承基类公有成员,在派生类中相当于是保护成员.继承基类保护成员,在派生类中相当于是保护成员
*/
class   Base
{
private:
	int a;
	int c;
};

class  Child :  Base
{
private:
	int b;
};

int main(int argc, char const *argv[])
{
	cout<<sizeof(Base)<<endl;
	cout<<sizeof(Child)<<endl;
	//sizeof(Child) 大小看出,派生类对象必定存在一个基类对象
	//与继承方式 基类成员访问模式无关
	return 0;
}