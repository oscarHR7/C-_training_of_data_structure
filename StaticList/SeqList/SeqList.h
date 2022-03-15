#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"../List/List.h"
#include"../Exception/Exception.h"

namespace DTLib
{ 
template
<typename T>
class SeqList :public List<T>//基类为泛型编程继承时注意格式
{
protected:
	T*  m_array;
	int m_length;
public:
	bool insert(const T& e)
	{
		return insert(m_length,e);
	}
	bool insert(int i, const T& e)
	{
		bool ret = ((i >= 0) && (i <= m_length));//注意大于等于和小于等于的标准写法
		ret = ret && (m_length < capacity());
		if (ret)
		{
			for (int place = m_length - 1; place >= i; place--)
			{
				m_array[place+1] = m_array[place];
			}
			m_array[i] = e;
			m_length++;
			
		}
			return ret;
	}
	
	bool remove(int i)
	{
		bool ret = ((i>=0) && (i<m_length));
		if (ret)
		{
			for (int place = i; place < m_length-1; place++)//注意上限应为数组中的最后一个数值
			{
				m_array[place] = m_array[place + 1];
			}
			m_length--;
		}
		return ret;
	}

	bool set(int i, const T& e)
	{
		bool ret = ((i >= 0) && (i < m_length ));
		if (ret)
		{
			m_array[i] = e;
		}
		return ret;
	}

	bool get(int i, T& e)const
	{
		bool ret = ((i >= 0) && (i < m_length ));
		if (ret)
		{
			e = m_array[i];
		}
		return ret;
	}

	int length()const
	{
		return m_length;
	}

	void clear()
	{
		m_length = 0;
	}
	
	T& operator[](int i)//非const访问重载
	{
		if((i >= 0) && (i < m_length))
		{ 
			return m_array[i];
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Element out-of-bounds");
		}
	}

	T  operator[](int i)const//const对象访问由于和非const的代码本质上一样所以采用代码复用先解除const属性然后去直接访问
	{
		return const_cast<SeqList<T>&>(*this)[i];
	}

	virtual int capacity()const = 0;
};

}

#endif