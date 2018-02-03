#include <iostream>
#include <assert.h>
using namespace std;
template<class _Tp1>
class define_auto_ptr_ref
{
public:
	_Tp1 * _M_ptr;
	explicit define_auto_ptr_ref(_Tp1 _p):_M_ptr(_p)
	{}
};
template<class _Tp>
class define_auto_ptr
{
private:
	_Tp * _M_ptr;
public:
	typedef _Tp element_type;
	explicit define_auto_ptr(element_type * _p=0) throw():_M_ptr(_p){}
	define_auto_ptr(define_auto_ptr& _a) throw():_M_ptr(_a.release()){}
	template<class _Tp1>
	define_auto_ptr(define_auto_ptr<_Tp1>& _a) throw():_M_ptr(_a.release()){}
	define_auto_ptr& operator =(define_auto_ptr * _a) throw()
	{
		reset(_a.release());
		return *this;
	}
	template<class _Tp1>
	define_auto_ptr& operator =(define_auto_ptr<_Tp1>& _a) throw()
	{
		reset(_a.release());
		return *this;
	}
	~define_auto_ptr()
	{
		delete _M_ptr;
	}
	element_type& operator*() const throw()
	{
		assert(_M_ptr!=0);
		return *_M_ptr;
	}

	element_type* operator ->() const throw()
	{
		assert(_M_ptr!=0);
		return _M_ptr;
	}

	element_type * get() const throw()
	{
		return _M_ptr;
	}


	element_type* release() throw()
	{
		element_type * _tmp=_M_ptr;
		_M_ptr=0;
		return _tmp;
	}

	void reset(element_type * _p=0) throw()
	{
		if(_p!=_M_ptr)
		{
			delete _M_ptr;
			_M_ptr=_p;
		}
	}

	define_auto_ptr(define_auto_ptr_ref<element_type> _ref) throw():_M_ptr(_ref._M_ptr){}
	define_auto_ptr&  operator =(define_auto_ptr_ref<element_type> _ref) throw()
	{
		if(_ref._M_ptr!=this->get())
		{
			delete _M_ptr;
			_M_ptr=_ref._M_ptr;
		}
		return *this;
	}

	template<class _Tp1>
	operator define_auto_ptr_ref<_Tp1>() throw()
	{
		return define_auto_ptr_ref<_Tp1>(this->release());
	}
	
	template<class _Tp1>
	operator define_auto_ptr<_Tp1>() throw()
	{
		return define_auto_ptr<_Tp1>(this->release());
	}
};