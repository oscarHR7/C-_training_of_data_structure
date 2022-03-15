#ifndef _STATICLIST_H_
#define _STATICLIST_H_

#include"../SeqList/SeqList.h"

namespace DTLib
{
template
<typename T,int N>
class StaticList: public SeqList<T>
{
protected:
	T m_space[N];
public:
	StaticList()
	{
		this->m_array = m_space;//this指针指向当前的对象，而当前对象继承父类所以this指针相当于可以指向继承父类的变量
		this->m_length = 0;//如果不加this那么将会无法找到父类中的成员变量，因为构造函数是对当前类进行操作
	}
	int capacity()const
	{
		return N;
	}

};
}
#endif