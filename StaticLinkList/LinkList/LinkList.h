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
		T value;//����ͷ���ʱ����ڵ����ⲿ�Զ����T���ʹӶ����³��������ⲿʹ�����͵Ĵ���������쳣
		Node* next;
	};

	mutable struct : public top_object//mutable ��Ҫ�������Ա����const���Է��ʸó�Ա�����ĵ�ַ
	{
		char reserved[sizeof(T)];//ͷ��������������ͷ���ֱ�ӽ��ж�����ʹ��T���͵Ĺ��캯��
		Node* next;
	}m_header;		//���ڸĶ����ͷ���һ��Ҫ��Node�Ľṹ��ʽһ������Ҫ�ǵü̳�top_object			
	
	int m_step;
	Node* m_current_pointer;//ʵ�ֱ����ĳ�Ա����
	int m_length;

	Node* position(int i) const//����ǰָ�����ϣ��������λ�ã�ģ�黯��̣����ض�λ�õ�ָ�뼴��
	{
		Node* current_pointer = reinterpret_cast<Node*>(&m_header);//header��Ҫǿ������ת����Ϊ���ͺ�Node��ͬ
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
		m_length = 0;				//���캯��һ��Ҫ�Գ�Ա������ȫ��ʼ��
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
				node->next = current_pointer->next;//current_pointerλ�ڲ���λ�õ�ǰһλ
				current_pointer->next = node;//current_pointer����һλָ�����ṹ����ɲ���
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
		bool ret = ((i >= 0) && (i < m_length));//ɾ��ʱ���ޱ���С��m_length
		if (ret)
		{
			Node* current_pointer = position(i);
			Node* delete_pointer = current_pointer->next;
			current_pointer->next = delete_pointer->next;
			destory(delete_pointer) ;//delete+ָ��=ɾ��ָ��ռ���ָ����
			m_length--;
		}
		else
		{
			THROW_EXCEPTION(IndexOutOfBoundsException, "delete out of bounds..");
		}
		return ret;
	}
	 
	bool set(int i, const T& Data_element)//������˵�ĵڼ������ݾ��Ƕ�Ӧ��������������±�
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
	
	 bool get(int i, T& Data_element) const//�ڲ�����������������������ʹ�ò�����ʶ�����getʵ�ֽ�����λ�ü��ɵ���
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

	virtual T get(int i) const//����get
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

	void clear ()//��յ�����
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
