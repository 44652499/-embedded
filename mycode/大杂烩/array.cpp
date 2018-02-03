/*
function:定义一个模板数组类
*/
#include <iostream>
using namespace std;
//定义实现排序函数指针类型

template<class T>
class array
{
typedef (*sortfunp)(T a,T b);
public :
  array(int _length)
  {
  	length=_length;
  	p=new T[length];
  }
  void inputdata()
  {
  	int i;
  	for(i=0;i<length;i++)
  	{
  		cin>>p[i];
  	}
  }
  //默认为升序
  void sortelement()
  {
    int i,j;
    for(i=0;i<length;i++)
    {
    	for(j=0;j<length-i-1;j++)
    	{
    		if(p[j]>p[j+1])
    		{
    			T tmp=p[j];
    			p[j]=p[j+1];
    			p[j+1]=tmp;
    		}
    	}
    }
  }
  //指定排序方式
  //fp:在类外,可以指定排序方式
  void sortelement(sortfunp fp)
  {
  	int i,j;
    for(i=0;i<length;i++)
    {
    	for(j=0;j<length-i-1;j++)
    	{
    		if(fp(p[j],p[j+1]))
    		{
    			T tmp=p[j];
    			p[j]=p[j+1];
    			p[j+1]=tmp;
    		}
    	}
    }
  }
  void outputdata()
  {
  	int i;
  	for(i=0;i<length;i++)
  	{
  		cout<<p[i]<<'\t';
  	}
  	cout<<endl;
  }

private:
	int length;
	T *p;
};

int main(int argc, char const *argv[])
{
	array<int> a1(5);
	a1.inputdata();
	a1.sortelement();
	a1.outputdata();
	return 0;
}
