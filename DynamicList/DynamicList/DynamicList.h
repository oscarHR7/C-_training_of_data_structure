#ifndef _DYNAMICLIST_H_
#define _DYNAMICLIST_H_

#include"../SeqList/SeqList.h"


namespace DTLib
{
template
<typename T>
class DynamicList : public SeqList<T>
{
protected:
	int m_capacity;
public:
	DynamicList(int capacity)
	{
		this->m_array = new T[capacity];
		if(this->m_array!=NULL)
		{ 
			this->m_length = 0;
			this->m_capacity = capacity;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "Failed to apply for memory..");
		}
	}
	int capacity()const//纯虚函数需要在其每个不同子类中进行定义
	{
		return m_capacity;
	}

	void resize(int capacity)//重置顺序存储的空间大小//此函数要求可以在调整内存空间的大小后尽量保证原始数据不变化依然按顺序存放
	{
		if (capacity != m_capacity)
		{
			T* array = new T[capacity];
			if (array != NULL)
			{
				int length = ((this->m_length >= capacity) ? capacity : this->m_length);
				for (int i = 0; i < length; i++)
				{
					array[i] = this->m_array[i];
				}
			
				T* last_array = this->m_array;//对重置前的内存空间进行释放防止内存泄漏
				this->m_array =  array;
				this->m_length  =  length;
				this->m_capacity = capacity;
				delete[]last_array;//对重置前的内存空间进行释放防止内存泄漏
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "Failed to apply for resize memory..");
			}
		}		
	}
	~DynamicList()
	{
		delete[](this->m_array);
	}
};


}


#endif