#include  <iostream>
using namespace std;
/*
任何一个类中都存在一个特殊指针 this 指针
this 指针表示:当前对象

*/
//定义点类
class Point
{
public:
	Point()
	{

	}
	Point(double _x,double _y)
	{
		this->x=_x;
		this->y=_y;
	}
	double x;
	double y;
};
//定义线条类
class Line
{
public:
	Line(Point _p1,Point _p2)
	{
		//可以赋值,Point类中存在一个默认operator = 
		p1=_p1;
		p2=_p2;
	}
	//计算线条斜率
	double  getLineK()
	{
		double  k=0;
		k=(p1.y-p2.y)/(p1.x-p2.x);
		return k;
	}
	//判断线条是否平行
	bool isParallel(Line l1,Line l2)
	{
		//double k1=this->getLineK();
		//double k2=this->getLineK();
		double k1=l1.getLineK();
		double k2=l2.getLineK();
		return k1==k2;
	}

	//判断线条是否平行
	bool isParallel(Line l)
	{
		double k1=this->getLineK();
		double k2=l.getLineK();
		return k1==k2;
	}
private:
	Point p1;//线条类的成员变量,需要调用无参构造函数
	Point p2;
};

int main(int argc, char const *argv[])
{
	Point p1(1,2),p2(3,4),p3(5,13),p4(7,8);
	Line l1(p1,p2);//调用拷贝构造函数
	Line l2(p3,p4);
	if(l1.isParallel(l2))//类中this 指针指向了l1
	{
		cout<<"ok"<<endl;
	}
	else
	{
		cout<<"not ok"<<endl;
	}
	return 0;
}