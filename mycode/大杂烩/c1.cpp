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
    //return 0;//���ػ��ͷžֲ�����,��exit���������ͷžֲ�ջ
    exit(0);//����Ϊʲô?
}
