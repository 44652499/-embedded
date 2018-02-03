#include <iostream>
using namepace std;
class A
{
public:
	A()
	{
		p=new int[3];
	}
	//增加释放对象指针成员指向堆空间
	void  freememory()
	{
		delete p;
		p=NULL;
	}
private:
	int *p;
};
int main(int argc, char const *argv[])
{
	A a1;
	A a2;
	//a1,a2局部对象,主函数结束自动释放.但是a1 a2 对象中存在一个指针,分别指向堆空间.出现堆空间泄漏

    //调用释放函数释放堆空间
	a1.freememory();
	a2.freememory();
	return 0;
}