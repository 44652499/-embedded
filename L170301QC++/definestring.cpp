#include <iostream>
#include <string.h>
#define  MAX_LEN 1024
using namespace std;
class  DefineString
{
friend ostream&  operator <<(ostream&  out,DefineString& s_obj);
friend istream&  operator >>(istream& in,DefineString & s_obj);
friend 
DefineString  operator  +(DefineString & s_obj_1,DefineString & s_obj_2);
friend DefineString  operator  +(DefineString & s_obj_1,const char * ch_src);
friend DefineString  operator  +(const char * ch_src,DefineString & s_obj_1);
public:
	DefineString()
	{
		ptr_ch=NULL;
		len=0;
	}

	DefineString(const char *  ch_src)
	{
		int ch_src_len=strlen(ch_src);
		len=ch_src_len;
		ptr_ch=new char[ch_src_len+1];
		bzero(ptr_ch,ch_src_len+1);
		strcpy(ptr_ch,ch_src);
	}
	DefineString(int  ch_len)
	{
		len=ch_len;
		ptr_ch=new char[ch_len+1];
		bzero(ptr_ch,ch_len+1);
	}
	DefineString(const char*  ch_src,int ch_len)
	{
		this->len=ch_len;
		this->ptr_ch=new char[this->len+1];
		bzero(this->ptr_ch,this->len+1);
		strncpy(this->ptr_ch,ch_src,ch_len);
	}
	DefineString(const DefineString& s_obj,int ch_len)
	{
		this->len=ch_len;
		this->ptr_ch=new char[this->len+1];
		bzero(this->ptr_ch,this->len+1);
		strncpy(this->ptr_ch,s_obj.ptr_ch,this->len);
	}
	DefineString(const char*  ch_src,int begin,int ch_len)
	{
		this->len=ch_len;
		this->ptr_ch=new char[this->len+1];
		int index=0;
		while(1)
		{
			if(ch_src[begin+index]=='\0')
				break;
			if(index>=ch_len)
				break;
			this->ptr_ch[index]=ch_src[begin+index];
			index++;
		}
	}
	DefineString(DefineString&  s_obj,int begin,int ch_len)
	{
		this->len=ch_len;
		this->ptr_ch=new char[this->len+1];
		int index=0;
		while(1)
		{
			if(s_obj.ptr_ch[begin+index]=='\0')
				break;
			if(index>=ch_len)
				break;
			this->ptr_ch[index]=s_obj.ptr_ch[begin+index];
			index++;
		}
	}
	
	DefineString(const DefineString& s_obj)
	{
		this->len=s_obj.len;
		this->ptr_ch=new char[this->len+1];
		bzero(this->ptr_ch,this->len+1);
		strcpy(this->ptr_ch,s_obj.ptr_ch);
	}
	void  operator =(DefineString s_obj)
	{
		if(this->ptr_ch!=NULL)
		{
			delete this->ptr_ch;
			this->ptr_ch=NULL;
		}
		this->len=s_obj.len;
		this->ptr_ch=new char[this->len+1];
		bzero(this->ptr_ch,this->len+1);
		strcpy(this->ptr_ch,s_obj.ptr_ch);
	}

	void  operator =(const char * ch_src)
	{
		if(this->ptr_ch!=NULL)
		{
			delete this->ptr_ch;
			this->ptr_ch=NULL;
		}
		this->len=strlen(ch_src);
		this->ptr_ch=new char[this->len+1];
		bzero(this->ptr_ch,this->len+1);
		strcpy(this->ptr_ch,ch_src);
	}
	~DefineString()
	{
		if(ptr_ch!=NULL)
		{
			delete[]  ptr_ch;
			ptr_ch=NULL;
		}
	}
private:
	char * ptr_ch;
	int  len;
};
istream&  operator >>(istream& in,DefineString & s_obj)
{
	if(s_obj.ptr_ch!=NULL)
	{
		delete  s_obj.ptr_ch;
		s_obj.ptr_ch=NULL;
	}
    s_obj.ptr_ch=new char[MAX_LEN+1];
    bzero(s_obj.ptr_ch,MAX_LEN+1);
	in>>s_obj.ptr_ch;
	return in;
}

ostream&  operator <<(ostream&  out,DefineString& s_obj)
{
	out<<s_obj.ptr_ch<<endl;
	return out;
}

DefineString  operator  +(DefineString & s_obj_1,DefineString & s_obj_2)
{
	DefineString s_obj;
	int s_len=s_obj_1.len+s_obj_2.len;
	s_obj.len=s_len;
	s_obj.ptr_ch=new char[s_obj.len+1];
	bzero(s_obj.ptr_ch,s_obj.len+1);
	strcpy(s_obj.ptr_ch,s_obj_1.ptr_ch);
	strcat(s_obj.ptr_ch,s_obj_2.ptr_ch);
	return s_obj;
}

DefineString  operator  +(DefineString & s_obj_1,const char * ch_src)
{
	DefineString s_obj;
	int s_len=s_obj_1.len+strlen(ch_src);
	s_obj.len=s_len;
	s_obj.ptr_ch=new char[s_obj.len+1];
	bzero(s_obj.ptr_ch,s_obj.len+1);
	strcpy(s_obj.ptr_ch,s_obj_1.ptr_ch);
	strcat(s_obj.ptr_ch,ch_src);
	return s_obj;
}

DefineString  operator  +(const char * ch_src,DefineString & s_obj_1)
{
	DefineString s_obj;
	int s_len=s_obj_1.len+strlen(ch_src);
	s_obj.len=s_len;
	s_obj.ptr_ch=new char[s_obj.len+1];
	bzero(s_obj.ptr_ch,s_obj.len+1);
	strcpy(s_obj.ptr_ch,s_obj_1.ptr_ch);
	strcat(s_obj.ptr_ch,ch_src);
	return s_obj;
}

int main(int argc, char const *argv[])
{
	DefineString  s_obj_1("abcdef");
	//cout<<s_obj_1;
	DefineString  s_obj_2;
	//cin>>s_obj_2;
	//cout<<s_obj_2;
    //DefineString  s_obj_3(10);
    //s_obj_3=s_obj_1;
    //cout<<s_obj_3;
    //s_obj_2=s_obj_1;
   // cout<<s_obj_1;

    //DefineString  s_obj_4(s_obj_1);
    //cout<<s_obj_4;

    //s_obj_2="acdef";
    //cout<<s_obj_2;

    DefineString s_obj_5("abcdefg",3);
    //DefineString s_obj_5(s_obj_1,2);
    //DefineString  s_obj_6("abcdefg",7,2);
    //DefineString  s_obj_6(s_obj_1,2,2);
    //cout<<s_obj_6;

    DefineString s_obj_7;
    //s_obj_7=s_obj_1+s_obj_5;
    //s_obj_7=s_obj_1+"12345";
    s_obj_7="12345"+s_obj_1;
    s_obj_7=s_obj_7+"111121";
    cout<<s_obj_7;
	return 0;
}