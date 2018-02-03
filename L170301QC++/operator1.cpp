#include  <iostream>
using namespace std;
/*
符号重载:c++符号增加支持自定类型的操作数.实际是一个特殊函数.函数名为:operator 符号
c++ 支持可重载符号:
  算术运算符：+,-,*,/,%,++,--
  位操作运算符：&,|,~,^,＜＜,＞＞
  逻辑运算符：!,&&,||;
  比较运算符：＜,＞,＞=,＜=,==,!=;
  赋值运算符：=,+=,-=,*=,/=,%=,&=,|=,^=,＜＜=,＞＞=;
  其他运算符：[],(),-＞,,(逗号运算符)
  operator new  operator new[]  operator delete  operator delete[]
  c++ 不支持重载符号:
  . 成员选择 
  .* 通过到成员的指针做成员选择 
  :: 作用域解析 
  ?: 三元条件运算符
  sizeof

  符号重载语法:
    返回值类型  operator 符号(参数列表);
 符号重载特点:
 1.不是创建一个新符号
 2.不改变符号优先级
 3.不改变符号的结合性
 4.不改变符号操作个数

 符号重载定义两个方式:
 1.类的成员函数
 2.友元函数
 类的成员函数重载,如果重载符号需要两个操作数,在定义是只需要一个参数,另一个用this代替
 如果重载符号需要一个操作数,在定义是无参,用this代替
 =,(),[] 和-＞ 只能使用成员函数方式重载

 友元函数:重载符号需要几个操作数就定义几个参数.
>>  << 只能使用友元函数方式重载
*/
//复数:a+bi
class complex  
{
friend istream&  operator >>(istream& in,complex&  c);
friend ostream&  operator <<(ostream & out,complex c);
public:
	complex(double _x=0,double _y=0)
	{
		x=_x;
		y=_y;
	}
	complex operator+(complex c)
	{
		return complex(this->x+c.x,this->y+c.y);
	}
private:
	double  x;
	double  y;
};
//为什么 >>  << 第一个参数 和返回值都必须是引用??
//支持连续输入输出
istream&  operator >>(istream& in,complex& c)
{
	in>>c.x>>c.y;
	return in;
}

ostream&  operator <<(ostream & out,complex c)
{
	out<<c.x<<"+"<<c.y<<"i"<<endl;
	return out;
}
int main(int argc, char const *argv[])
{
	//complex c1(1,2),c2(3,4);
	complex c1,c2;
	cin>>c1>>c2;
	complex  c3=c1+c2;
	cout<<c3<<endl;
	return 0;
}