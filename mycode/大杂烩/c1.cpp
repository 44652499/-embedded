#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout<<"A 1"<<endl;
    }
    ~A()
    {
        cout<<"A disconstructor"<<endl;
    }
};
int main(int argc, char const *argv[]) {
    A a1;
    //return 0;//返回会释放局部变量,但exit函数不会释放局部栈
    exit(0);//想想为什么?
}
