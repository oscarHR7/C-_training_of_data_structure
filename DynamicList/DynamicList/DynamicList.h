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
	int capacity()const//���麯����Ҫ����ÿ����ͬ�����н��ж���
	{
		return m_capacity;
	}

	void resize(int capacity)//����˳��洢�Ŀռ��С//�˺���Ҫ������ڵ����ڴ�ռ�Ĵ�С������֤ԭʼ���ݲ��仯��Ȼ��˳����
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
			
				T* last_array = this->m_array;//������ǰ���ڴ�ռ�����ͷŷ�ֹ�ڴ�й©
				this->m_array =  array;
				this->m_length  =  length;
				this->m_capacity = capacity;
				delete[]last_array;//������ǰ���ڴ�ռ�����ͷŷ�ֹ�ڴ�й©
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