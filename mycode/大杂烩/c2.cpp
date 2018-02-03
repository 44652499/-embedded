#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout<<"A 1"<<endl;
    }

    A(const A &a)
    {
        cout<<"copy constructor"<<endl;
    }
    //void operator =(A a)
    void operator =(A& a)
    {
        cout<<"operator ="<<endl;
    }
    ~A()
    {
        cout<<"A disconstructor"<<endl;
    }
};

void fun1( A  a)
{

}

A fun2( A  a)
{
    A ret;
    return ret;
}
A& fun3()
{
    A ret;
    return ret;
}
int main(int argc, char const *argv[]) {
 A a1;
 //A a2=a1; //copy constructor
//A a2(a1);//copy constructor
//fun1(a1);//copy constructor
//fun2(a1);//copy constructor
//fun3();//A()
A a4=fun3();//copy constructor
//A a2;
//a2=a1;//void operator =(A a)  copy constructor
}
