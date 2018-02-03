#include  <iostream>
using namespace std;
/*
友元类:两个类,一个类可以访问另一个类的私有成员
声明友元类:
friend class 类名;
*/
//定义点类
class Point
{
friend  class Line;//声明线条类时点类友元类
public:
	Point()
	{

	}
	Point(double _x,double _y)
	{
		x=_x;
		y=_y;
	}
private:
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
		double k1=l1.getLineK();
		double k2=l2.getLineK();
		return k1==k2;
	}
private:
	Point p1;//线条类的成员变量,需要调用无参构造函数
	Point p2;
};

int main(int argc, char const *argv[])
{
	Point p1(1,2),p2(3,4),p3(5,6),p4(7,8);
	Line l1(p1,p2);//调用拷贝构造函数
	Line l2(p3,p4);
	if(l1.isParallel(l1,l2))
	{
		cout<<"ok"<<endl;
	}
	else
	{
		cout<<"not ok"<<endl;
	}
	return 0;
}