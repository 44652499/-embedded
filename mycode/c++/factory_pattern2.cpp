#include <iostream>
using namespace std;
/*
工厂设计模式提供了一个共同的接口来指向新创建的对象,避免用new创建对象
优点: 
1、一个调用者想创建一个对象,只要知道其名称就可以了.
2、扩展性高,如果想增加一个产品,只要扩展一个工厂类就可以.
3、屏蔽产品的具体实现,调用者只关心产品的接口
*/

//抽象工厂模式:提供一个创建一系列相关或相互依赖对象的接口,而无需指定它们具体的类
class  User
{
public:
	virtual  void print_user()=0;
};
class Department
{
public:
	virtual void  print_department()=0;
};
class SqlserverUser:public User
{
public:
	void print_user()
	{
		cout<<"SqlserverUser"<<endl;
	}
};
class AccessUser:public User
{
public:
	void print_user()
	{
		cout<<"AcessUser"<<endl;
	}
};

class SqlserverDepartment:public Department
{
public:
	void  print_department()
	{
		cout<<"SqlserverDepartment"<<endl;
	}
};
class AccessDepartment:public Department
{
public:
	void  print_department()
	{
		cout<<"AccessDepartment"<<endl;
	}
};

class Factory
{
public:
	virtual User*  createUser()=0;
	virtual Department* createDepartment()=0;
};
class SqlserverFactory:public Factory
{
public:
	 User*  createUser()
	 {
          return new SqlserverUser();
	 }
	 Department* createDepartment()
	 {
	 	  return new SqlserverDepartment();
	 }
};
class AccessFactory:public Factory
{
public:
	 User*  createUser()
	 {
	 	return new AccessUser();
	 }
	 Department* createDepartment()
	 {
	 	return new AccessDepartment();
	 }
};
int main(int argc, char const *argv[])
{
	Factory * f=new SqlserverFactory();
	User  *u=f->createUser();
	Department *d=f->createDepartment();
	u->print_user();
	u->print_department();

	f=new AccessFactory();
	u=f->createUser();
	d=f->createDepartment();
	u->print_user();
	u->print_department();
	return 0;
}