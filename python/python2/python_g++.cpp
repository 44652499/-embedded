#include <Python.h>
int main(int argc, char** argv)  
{  
    // 初始化Python  
    //在使用Python系统前，必须使用Py_Initialize对其  
    //进行初始化。它会载入Python的内建模块并添加系统路  
    //径到模块搜索路径中。这个函数没有返回值，检查系统  
    //是否初始化成功需要使用Py_IsInitialized。  
    Py_Initialize();    
    // 检查初始化是否成功  
    if (!Py_IsInitialized()) 
    {  
        return -1;  
    }  
    //添加当前路径  
    //把输入的字符串作为Python代码直接运行，返回0  
    PyRun_SimpleString("import sys");  
    PyRun_SimpleString("print '---import sys---'");   
    PyRun_SimpleString("sys.path.append('./')");  
    PyObject *pName,*pModule,*pDict,*pFunc,*pArgs;  
  
    // 载入名为pytest的脚本  
    pName = PyString_FromString("pytest");  
    pModule = PyImport_Import(pName);  
    if(!pModule) 
    {  
        printf("can't find pytest.py");  
        getchar();  
        return -1;  
    }  
    pDict = PyModule_GetDict(pModule);  
    if (!pDict) 
    {  
        return -1;  
    }    
    //找出函数名为add的函数  
    printf("----------------------\n");  
    pFunc = PyDict_GetItemString(pDict, "add");  
    if(!pFunc || !PyCallable_Check(pFunc)) 
    {  
        printf("can't find function [add]");  
        getchar();  
        return -1;  
     }    
    //参数进栈  *pArgs;  
    pArgs = PyTuple_New(2);  
  
    //  PyObject* Py_BuildValue(char *format, ...)  
    //  把C++的变量转换成一个Python对象。当需要从  
    //  C++传递变量到Python时，就会使用这个函数。此函数  
    //  有点类似C的printf，但格式不同。常用的格式有  
    //  s 表示字符串，  
    //  i 表示整型变量，  
    //  f 表示浮点数，  
    //  O 表示一个Python对象。  
  
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("l",3));  
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("l",4));  
  
    // 调用Python函数  
    PyObject_CallObject(pFunc, pArgs);  
  
    //下面这段是查找函数sub 并执行sub  
    printf("----------------------\n");  
    pFunc = PyDict_GetItemString(pDict, "sub");  
    if (!pFunc || !PyCallable_Check(pFunc)) 
    {  
        printf("can't find function [sub]");  
        getchar();  
        return -1;  
     }    
    pArgs = PyTuple_New(2);  
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("l",20));  
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("l",2)); 
    PyObject_CallObject(pFunc, pArgs);         
    printf("----------------------\n");  
    pFunc = PyDict_GetItemString(pDict, "update");  
    if (!pFunc || !PyCallable_Check(pFunc) ) 
    {  
        printf("can't find function [update]");  
        getchar();  
        return -1;  
     }  
    pArgs = PyTuple_New(0);  
    PyTuple_SetItem(pArgs, 0, Py_BuildValue(""));  
    PyObject_CallObject(pFunc, pArgs);       
  
    Py_DECREF(pName);  
    Py_DECREF(pArgs);  
    Py_DECREF(pModule);  
  
    // 关闭Python  
    Py_Finalize();  
    return 0;  
}   
/*
编译注意事项:
1.虚拟机 linux fedora21 中已经存在python 解释器
  可以用下面的命令测试:
  [root@localhost python]# python
  将会出现如下提示界面:
  Python 2.7.8 (default, Sep 24 2015, 18:25:44) 
2.输入 quit()  将退出python 回到终端界面
3.python 脚本 c++代码编写完毕后,保存在同一个目录中
4.在终端里面运行如下命令,安装python-devel开发包,注意必须要让虚拟连上网
  [root@localhost include]# dnf install python-devel
5.安装成功后,执行如下编译语句
 [root@localhost python]# g++ -I /usr/include/python2.7/ -L /usr/lib/python2.7/ -lpython2.7 python_g++.cpp -o python_g++
6.执行  ./python_g++
*/