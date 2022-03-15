#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

#include "../Pointer/Pointer.h"

namespace DLTib 
{
template
<typename T>
class SmartPointer :public Pointer<T>
{
public:
	SmartPointer(T* pointer = NULL):Pointer<T>(pointer)//直接调用父类的构造函数
	{
	}
	SmartPointer(const SmartPointer<T>& obj)
	{
		this->m_pointer = obj.m_pointer;
		const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;//去掉只读属性
	}

	SmartPointer<T>& operator = (const SmartPointer<T>& obj)
	{
		if ( this != &obj )
		{
			T* p = this->m_pointer;//异常安全处理
			this->m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;//去掉只读属性
			delete p;
		}
		return *this;
	}

	~SmartPointer()
	{
		delete this->m_pointer;
	}
};



}


#endif 

