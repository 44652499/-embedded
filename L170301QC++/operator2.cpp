#include  <iostream>
using namespace std;
/*
实现平面的任意点计算(坐标值计算+ -),标准输入 输出,要求用友元方式重载
*/
class point
{
friend point  operator+(point p1,point p2);
friend point  operator-(point p1,point p2);
friend istream&  operator >>(istream& in,point& p);
friend ostream&  operator <<(ostream & out,point p);
public:
  	point(double _x=0,double _y=0)
  	{
  		x=_x;
  		y=_y;
  	}
private:
  	double x;
  	double y;
};
point  operator+(point p1,point p2)
{
  return point(p1.x+p2.x,p1.y+p2.y);
}

point  operator-(point p1,point p2)
{
	return point(p1.x-p2.x,p1.y-p2.y);
}

istream&  operator >>(istream& in,point& p)
{
	in>>p.x>>p.y;
	return in;
}
ostream&  operator <<(ostream & out,point p)
{
	out<<"("<<p.x<<","<<p.y<<")"<<endl;
	return out;
}

int main(int argc, char const *argv[])
{
    point p1,p2;
    cin>>p1>>p2;
    point p3=p1+p2;
    point p4=p1-p2;
    cout<<p3<<endl;
    cout<<p4<<endl;
	return 0;
}