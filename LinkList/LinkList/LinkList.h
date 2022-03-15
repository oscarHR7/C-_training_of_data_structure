#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "../List/List.h"
#include "../top_object/top_object.h"
#include "../Exception/Exception.h"

namespace DTLib
{
template< typename T>
class LinkList : public List<T>
{
protected:
	struct Node : public top_object
	{
		T value;//构建头结点时会存在调用外部自定义的T类型从而导致程序由于外部使用类型的错误而产生异常
		Node* next;
	};

	mutable struct : public top_object//mutable 主要是允许成员函数const可以访问该成员变量的地址
	{
		char reserved[sizeof(T)];//头结点存在隐患，对头结点直接进行定义规避使用T类型的构造函数
		Node* next;
	}m_header;		//对于改动后的头结点一定要和Node的结构形式一致尤其要记得继承top_object			
	
	int m_step;
	Node* m_current_pointer;//实现遍历的成员变量
	int m_length;

	Node* position(int i) const//将当前指针放在希望操作的位置，模块化编程，返回定位好的指针即可
	{
		Node* current_pointer = reinterpret_cast<Node*>(&m_header);//header需要强制类型转换因为类型和Node不同
		for (int count = 0; count < i; count++)
		{
			current_pointer = current_pointer->next;
		}
		return current_pointer;
	}

	virtual Node* create()
	{
		return new Node();
	}

	virtual void destory(Node* pn)
	{
		delete pn;
	}
public:
	LinkList() 
	{
		m_header.next = NULL;
		m_step = 1;
		m_current_pointer = NULL;
		m_length = 0;				//构造函数一定要对成员变量完全初始化
	}
	
	bool insert(const T& Data_element)
	{
		return insert(m_length, Data_element);
	}

	bool insert(int i, const T& Data_element)
	{
		bool ret = ((i >= 0)&&(i <= m_length));
		if (ret)
		{
			Node* node = create();
			if (node != NULL)
			{
				Node* current_pointer = position(i);
				node->value = Data_element;
				node->next = current_pointer->next;//current_pointer位于插入位置的前一位
				current_pointer->next = node;//current_pointer将下一位指向插入结构体完成插入
				m_length++;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory new fail..");
			}
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Insert out of bounds..");
		}
		return ret;
	}
	
	bool remove(int i)
	{
		bool ret = ((i >= 0) && (i < m_length));//删除时上限必须小于m_length
		if (ret)
		{
			Node* current_pointer = position(i);
			Node* delete_pointer = current_pointer->next;
			current_pointer->next = delete_pointer->next;
			destory(delete_pointer) ;//delete+指针=删除指针空间所指内容
			m_length--;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "delete out of bounds..");
		}
		return ret;
	}
	 
	bool set(int i, const T& Data_element)//这里所说的第几个数据就是对应于类似于数组的下标
	{
		bool ret = ((i >= 0) && (i < m_length));
		if (ret)
		{
			position(i)->next->value = Data_element;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Set_Data out of bounds..");
		}
		return ret;
	}
	
	 bool get(int i, T& Data_element) const//在操作过程中有两个参数变量使用不方便故而重载get实现仅输入位置即可调用
	{
		bool ret = ((i >= 0) && (i < m_length));
		if (ret)
		{
			Data_element = position(i)->next->value;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Get_Data out of bounds..");
		}
		return ret;
	}

	virtual T get(int i) const//重载get
	{
		T Data_element;
		if (get(i, Data_element))
		{
			return Data_element;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Get_Data out of bounds..");
		}
	}

	int find(const T& Data_element) const
	{
		int ret = -1;
		int count = 0;
			Node* current_pointer = m_header.next;
			while (current_pointer)
			{
				if (current_pointer->value == Data_element)
				{
					ret = count;
					break;
				}
				else
				{
					current_pointer = current_pointer->next;
					count++;
				}
				
			}
		return ret;
	}

	virtual bool move(int i, int step = 1)
	{
		bool ret = (0 <= i) && (i<m_length) && (step>0);
		if(ret)
		{ 
			m_current_pointer = position(i)->next;
			m_step = step;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "Move out of bounds..");
		}
		return ret;
	}

	virtual bool end()
	{
		return (m_current_pointer == NULL);
	}

	virtual T current()
	{
		if (m_current_pointer != NULL)
		{
			return (m_current_pointer->value);
		}
		else
		{
			THROW_EXCEPTION(InvalidParameterException, "NO value in now current..");
		}
			
	}

	virtual bool next()
	{
		int i = 0;
		while ((i < m_step) && !end())
		{
			m_current_pointer = m_current_pointer->next;
			i++;
		}
		return (i == m_step);
	}

	int length() const
	{
		return  m_length;
	}

	void clear ()//清空单链表
	{
		Node* current_pointer = m_header.next;
		Node* delete_pointer = current_pointer;
		while (current_pointer)
		{
			delete_pointer = current_pointer;
			current_pointer = current_pointer->next;
			destory(delete_pointer) ;
		}
	}
	~LinkList()
	{
		clear();
	}
};


}





#endif
