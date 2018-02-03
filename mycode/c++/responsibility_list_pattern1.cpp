#include <iostream>
#include <string>
using namespace std;
/*
责任链模式是一种对象的行为模式,在责任链模式里,很多对象由每一个对象对其下家的引用而连接起来形成一条链.
请求在这个链上传递,直到链上的某一个对象决定处理此请求.发出这个请求的客户端并不知道链上的哪一个对象最终处理这个请求,这使得系统可以在不影响客户端的情况下动态地重新组织和分配责任

采用责任链模式的好处:
1.审核者之间松耦合,每一级审核者只需要知道下一级审核者就可以了,而无需知道上一级审核角色和审核结果.
2.客户端可以重新组装责任链,因而审核者的审核顺序可以随意调换.
3.可以在原有的责任链上任意位置随意新增审核角色,只需要修改客户端代码就可以了
*/
class Auditor
{
public:
	Auditor()
	{
		successor=NULL;
	}
	Auditor*  getSuccessor()
	{
		return successor;
	}
	void  setSuccessor(Auditor*  _successor)
	{
		successor=_successor;
	}
	virtual void  auditorProjectRequest(string projectId)=0;
private:
	Auditor*  successor;
};
class Teacher:public Auditor
{
public:
	void  auditorProjectRequest(string projectId)
	{
		if(projectId=="1" || projectId=="2" || projectId=="3")
		{
			cout<<"Teacher pass"<<endl;
			if(getSuccessor()!=NULL)
		    {
			   getSuccessor()->auditorProjectRequest(projectId);
		    }
		}
		else
		{
			cout<<"Teacher not pass"<<endl;
		}

	}
};

class Club:public Auditor
{
public:
	void  auditorProjectRequest(string projectId)
	{
		if(projectId=="1" || projectId=="2")
		{
			cout<<"Club pass"<<endl;
			if(getSuccessor()!=NULL)
		    {
			   getSuccessor()->auditorProjectRequest(projectId);
		    }
		}
		else
		{
			cout<<"Club not pass"<<endl;
		}

	}
};

class Admin:public Auditor
{
public:
	void  auditorProjectRequest(string projectId)
	{
		if(projectId=="1")
		{
			cout<<"Amin pass"<<endl;
			if(getSuccessor()!=NULL)
		    {
			   getSuccessor()->auditorProjectRequest(projectId);
		    }
		}
		else
		{
			cout<<"Amin not pass"<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Auditor* a1=new Teacher();
	Auditor* a2=new Club();
	Auditor* a3=new Admin();
	a1->setSuccessor(a2);
	a2->setSuccessor(a3);

	cout<<"project 0 :"<<endl;
	a1->auditorProjectRequest("0");
	cout<<endl;

	cout<<"project 1 :"<<endl;
	a1->auditorProjectRequest("1");
	cout<<endl;

	cout<<"project 2 :"<<endl;
	a1->auditorProjectRequest("2");
	cout<<endl;

	cout<<"project 3 :"<<endl;
	a1->auditorProjectRequest("3");
	cout<<endl;
	return 0;
}
