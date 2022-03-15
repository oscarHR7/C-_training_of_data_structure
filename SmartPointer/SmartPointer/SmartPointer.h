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
	SmartPointer(T* pointer = NULL):Pointer<T>(pointer)//ֱ�ӵ��ø���Ĺ��캯��
	{
	}
	SmartPointer(const SmartPointer<T>& obj)
	{
		this->m_pointer = obj.m_pointer;
		const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;//ȥ��ֻ������
	}

	SmartPointer<T>& operator = (const SmartPointer<T>& obj)
	{
		if ( this != &obj )
		{
			T* p = this->m_pointer;//�쳣��ȫ����
			this->m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;//ȥ��ֻ������
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

