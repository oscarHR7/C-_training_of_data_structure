#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

#include"../LinkList/LinkList.h"

namespace DTLib
{
template
<typename T>
class CircleList : public LinkList<T>
{
protected :
	
	typedef typename LinkList<T> ::Node Node; //��Ϊ�ڸ�����Node�ڽṹ������<T>�й�ϵ�ʶ���Ҫ��ͬʱͨ��typename˵��NodeΪһ�����Ͷ��ǳ�Ա����
	
	Node* last ()const
	{
		return this->position(this->m_length - 1);
	}
	void last_to_first()const
	{
		last()->next = this->m_header.next;
	}

	int mod(int i) const//i�Ĺ�һ��
	{
		return (this->m_length == 0) ? 0 :( i % this->m_length);
	}

public:
	bool insert(const T& Data_element)
	{
		return insert(this->m_length, Data_element);
	}

	bool insert(int i , const T& Data_element)
	{
		bool ret = true;
		i = i % (this->m_length + 1);//ͨ��ȡ������֤i����ʹ�õ��������
		ret = LinkList<T>::insert(i, Data_element);
		if (ret && (i == 0))//ע�����λ��Ϊ0��
		{
			last_to_first();
		}
		return ret;
	}

	bool remove(int i)
	{
		bool ret = true;
		i = mod(i);
		if (i == 0)
		{
			Node* delete_pointer = this->m_header.next;
			if (delete_pointer != NULL)
			{
				this->m_header.next = delete_pointer->next;
				this->m_length--;

				if (this->m_length > 0)
				{
					last_to_first();

					if (this->m_current_pointer == delete_pointer)
					{
						this->m_current_pointer = delete_pointer->next;
					}
				}
				else
				{
					this->m_header.next = NULL;
					this->m_current_pointer = NULL;
				}
				this->destory(delete_pointer);
			}
			else
			{
				ret = false;
			}

		}
		else
		{
			ret = LinkList<T>::remove(i);
		}
		return ret;
	}

	bool set(int i, const T& Data_element)
	{
		return LinkList<T>::set(mod(i), Data_element);
	}

	T get(int i)
	{
		return LinkList<T>::get(mod(i));
	}

	T get(int i, const T& Data_element)
	{
		return LinkList<T>::get(mod(i), Data_element);
	}

	int find(const T& Data_element) const
	{
		int ret = -1;
		
		Node* silder = this->m_header.next;
		for (int count = 0; count < this->m_length; count++)
		{
			if (silder->value == Data_element)
			{
				ret = count;
				break;
			}
			silder = silder->next;
		}
		return ret;
	}

	void clear()
	{
		while (this->m_length > 1)
		{
			remove(1);//remove 0 �ᵼ�´������ƶ�ʱ�临�Ӷ��½�
		}
		if (this->m_length == 1)
		{
			Node* delete_pointer = this->m_header.next;

			this->m_header.next = NULL;
			this->m_length = 0;
			this->m_current_pointer  = NULL;

			this->destory(delete_pointer);
		}
	}

	bool move(int i, int step)
	{
		return LinkList<T>::move(mod(i), step);
	}

	bool end()
	{
		return ((this->m_length == 0) || (this->m_current_pointer == NULL));
	}


	~CircleList()
	{
		clear();
	}

};
}



#endif 