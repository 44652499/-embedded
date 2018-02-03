#include <iostream>
#include "string.h"
#include "stdlib.h"
using namespace std;
class String//定义字符串类  
{
private://私有区  
     char *ptr;//字符串的首地址  
     int length;//字符串长度  
public://构造/重载函数区
    String(){ptr=0;length=0;} //默认构造函数    
    String(const char *s)//重载带参数的构造函数
    {  
        int len=strlen(s);  
        if (len>0)  
        {  
            ptr=new char[len+1];  
            strcpy(ptr,s);  
        }  
        else ptr=0;  
        length=len;  
    }    
    String(const String &s)//拷贝构造函数 
    {  
        if (ptr) delete[]ptr;  
        if (s.length>0)  
        {  
            ptr=new char[s.length+1];  
            strcpy(ptr,s.ptr);  
        }  
        else ptr=0;  
        length=s.length;  
    }   
 
/*-------------------------------------友元重载符号区------------------------------------------------*/
    String& operator =(String&);//重载赋值运算符“=”(不能用友元函数重载)  
    String& operator =(char *);//重载赋值运算符“=”(不能用友元函数重载)
    friend void strcat(String& s1,char* s2);//相当于s1+="..."  
    friend ostream& operator <<(ostream&,String&);  
    friend istream& operator >>(istream&,String&); 
    friend String operator +(String &s1,String &s2);//可改用成员函数  
    friend String operator +(String &s1,char* s2);//可改用成员函数  
    friend String operator +(char* s1,String &s2);//可改用成员函数
    friend int operator ==(String &s1,String &s2);//可改用成员函数  
    friend int operator ==(String &s1,const char* s2);//可改用成员函数//歧义  
    friend int operator ==(const char* s1,String &s2);//可改用成员函数//歧义     
/*---------------------------------------功能实现区--------------------------------------------------*/ 
    String Substr(int index,int count);//从index开始提取count个字符的子串  
    int Find(char c,int start);//从下标start开始找到c后，返回字符c在本串的下标  
    int IsEmpty();//判本串是否为空串  
    void clear();//清本串为空串  
    char& operator [](int n)//重载下标运算符“[]”  
    {  
        if (n<0 || n>=length)  
        {  
            cout<<"下标超界!\n";  
            exit(0);  
        }  
        return this->ptr[n];  
    }
    operator char*()//类型转换函数  
    { 
        return ptr; 
    }    
    void Print()//字符串的输出函数  
    {    
    if (length>0)  
         cout<<ptr<<endl;  
    else  
         cout<<"<null>"<<endl;  
    }            
    ~String()//析构函数  
    {
        if (ptr) delete []ptr;
    }  
};

String& String::operator =(String& s)//重载“=”运算符  
{  
     if (ptr) delete[] ptr;  
     if (s.length>0)  
     {  
         ptr=new char[s.length+1];  
         strcpy(ptr,s.ptr);  
     }  
     else ptr=0;  
     length=s.length;  
     return *this;  
}  
String& String::operator =(char *s)//重载“=”运算符  
{  
     if (ptr) delete[] ptr;  
     int len=strlen(s);  
     if (len>0)  
     {  
         ptr=new char[len+1];  
         strcpy(ptr,s);  
     }  
     else ptr=0;  
     length=len;  
     return *this;  
}
String operator +(String &s1,String &s2)//重载“+”运算符  
{  
     char *t;  
     int l1,l2;  
     l1=s1.length;  
     l2=s2.length;  
     if (l1+l2>0)  
     {  
         t=new char[l1+l2+1];  
         if (l1>0)  
         {  
             strcpy(t,s1.ptr);  
             if (l2>0)   strcat(t,s2.ptr);  
         }  
         else   //l1=0时,l2>0  
             strcpy(t,s2.ptr);  
     }  
     else t="\0";  
     return String(t);  
}
String operator +(String &s1,char* s2)//重载“+”运算符  
{  
    char* t;  
    int l1,l2;  
    l1=s1.length;  
    l2=strlen(s2);  
    if (l1+l2>0)  
    {  
        t=new char[l1+l2+1];  
        if (l1>0)  
        {  
            strcpy(t,s1.ptr);  
            if (l2>0) strcat(t,s2);  
        }  
    else strcpy(t,s2);  
    }  
    else t="\0";  
    return String(t);  
}  
String operator +(char* s1,String &s2)//重载“+”运算符  
{  
    char* t;  
    int l1,l2;  
    l1=strlen(s1);  
    l2=s2.length;  
    if (l1+l2>0)  
    {  
       t=new char[l1+l2+1];  
       if (l1>0)  
       {  
          strcpy(t,s1);  
          if (l2>0) strcat(t,s2.ptr);  
       }  
       else strcpy(t,s2.ptr);  
    }  
    else t="\0";  
    return String(t);  
}
int operator ==(String &s1,String &s2)//重载“==”运算符  
{  
    if (strcmp(s1.ptr,s2.ptr)==0)  
       return true;  
    else  
       return false;  
}  

int operator ==(String &s1,const char* s2)//重载“==”运算符//有歧义   
{  
    if (strcmp(s1.ptr,s2)==0)  
       return true;  
    else  
       return false;  
} 

int operator ==(const char* s1,String &s2)//重载“==”运算符//有歧义   
{  
    if (strcmp(s1,s2.ptr)==0)  
       return true;  
    else  
       return false;  
}

/*------------------------------------重载输入输出符号------------------------------------------------*/ 
ostream& operator <<(ostream &out,String& s)//友元函数,不能用成员函数  
{     
    if (s.ptr)  
       out<<s.ptr;  
    else  
       out<<"NULL";  
 return out;  
}  
istream& operator >>(istream &in,String &s)//友元函数,不能用成员函数  
{     
    if (s.ptr) delete[] s.ptr;  
    char *str=new char[2048];  
    in>>str;  
    int len=strlen(str);  
    if (len>0)  
    {  
       s.ptr=new char[len+1];  
       strcpy(s.ptr,str);  
       s.length=len;  
    }  
    else { s.ptr=0;s.length=0; }  
    delete[] str;  
    return in;  
} 
/*------------------------------------重载strcat()函数------------------------------------------------*/  
void strcat(String& s1,char *s2)//友元函数,重载strcat()函数,第一个参数为char*的不需重载  //有歧义问题
{  
    int l1,l2;  
    l1=s1.length;  
    l2=strlen(s2);  
    if (l1+l2>0)  
    {  
       if (l1>0)  
       {  
          char* t;  
          t=new char[l1+1];  
          strcpy(t,s1.ptr);  
          delete []s1.ptr;  
          s1.ptr=new char[l1+l2+1];  
          strcpy(s1.ptr,t);  
          if (l2>0) strcat(s1.ptr,s2);  
       }  
       else//l1=0,l2>0的情况  
          strcpy(s1.ptr,s2);  
       s1.length=l1+l2;//l1+l2=0时,s1仍为空串,故不需处理  
    }        
}

int main(int argc, char const *argv[])
{
	String s1="asda";
	String s2="asd";
	String s3="ssad";
    // cout<<"测试String==String功能：";  
    // if (s1==s3)             //operator ==(String,String),重载“==”  
    //     cout<<s1<<'='<<s3<<endl;  
    // else  
    //     cout<<s1<<"!="<<s3<<endl;
/*------------------------------有歧义-----------------------------------------------------------------*/
    // cout<<"测试String==char*功能：";  
     if (s3=="Public")     //operator ==(String,char*),重载“==”  
         cout<<s3<<'='<<"Public"<<endl;  
     else  
         cout<<s3<<"!="<<"Public"<<endl;  
     cout<<"测试char*==String功能：";  
     if ("Public1"==s3)     //operator ==(char*,String),重载“==”  
         cout<<s3<<'='<<"Public1"<<endl;  
     else  
         cout<<s3<<"!="<<"Public1"<<endl;
	// test2.cpp:244: 错误：ISO C++ 认为有歧义，尽管第一个备选的最差类型转换要好于第二个备选的最差类型转换
	// test2.cpp:168: 附注：备选 1： int operator==(char*, String&)
	// test2.cpp:244: 附注：备选 2： operator==(const char*, const char*) <内建>
	// test2.cpp:248: 错误：ISO C++ 认为有歧义，尽管第一个备选的最差类型转换要好于第二个备选的最差类型转换
	// test2.cpp:175: 附注：备选 1： int operator==(String&, char*)
	// test2.cpp:248: 附注：备选 2： operator==(const char*, const char*) <内建>
/*------------------------------有歧义------------------------------------------------------------------*/    
	strcat(s1," University");//调用重载函数strcat(String,char*)  
	//cout<<"执行strcat(s1,\" University\");后，s1="<<s1<<endl;
	//test2.cpp:260: 错误：ISO C++ 认为有歧义，尽管第一个备选的最差类型转换要好于第二个备选的最差类型转换
	//test2.cpp:209: 附注：备选 1： void strcat(String&, char*)
	//usr/include/string.h:93: 附注：备选 2： char* strcat(char*, const char*)
	return 0;
}
