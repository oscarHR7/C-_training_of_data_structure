#ifndef _POINTER_H_
#define _POINTER_H_

#include "../top_object/top_object.h"

namespace DTLib
{
template
<typename T>
class Pointer : public top_object
{
protected :
	T* m_pointer;
public:
	Pointer(T* p = NULL)
	{
		m_pointer = p;
	}
	T* operator -> ()
	{
		return m_pointer;
	}
	T* operator*   ()
	{
		return *m_pointer;
	}
	bool isNull()
	{
		return (m_pointer == NULL);
	}
	T* get()
	{
		return m_pointer;
	}
	//����Ҫ�鹹��������Ϊ�̳�top_object���и��౾���Ƕ���Ϊ���麯��
};



}



#endif