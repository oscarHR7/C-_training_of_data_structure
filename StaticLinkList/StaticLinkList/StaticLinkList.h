#ifndef _STATICLINKLIST_H_
#define _STATICLINKLIST_H_

#include "../LinkList/LinkList.h"


namespace DTLib
{
	template
	<typename T, int N >//����ģ���������Ԥ���ռ��Сʹ��
	class StaticLinkList : public LinkList<T>
	{
	protected:
		typedef typename LinkList<T>::Node Node; //typename ָ��NodeΪһ��������Ǳ��� ��Ϊ�����а�����T

		struct SNode : public Node
		{
			void* operator new(unsigned int size, void* loc)//���ع��캯��
			{
				(void)size;//sizeδʹ�õı�������ʽ
				return loc;
			}
		};

		unsigned char m_space[sizeof(SNode)*N];//Ԥ���ڴ�
		int m_used[N];//��¼��ӦN���Ƿ��Ѿ������������������Ϊ1

		Node* create()
		{
			SNode* ret = NULL;
			for (int count = 0; count < N; count++)
			{
				if (!m_used[count])
				{
					ret = reinterpret_cast<SNode*>(m_space) + count;
					ret = new(ret)SNode();
					m_used[count] = 1;
					break;
				}
			}
			return ret;
		}

		void destory(Node* pn)
		{
			SNode* space = reinterpret_cast<SNode*>(m_space);
			SNode* psn = dynamic_cast<SNode*>( pn );//����ָ��ת��Ϊ����
			for (int count = 0; count < N; count++)
			{
				if (psn == (space + count))
				{
					m_used[count] = 0;
					psn->~SNode();
				}
			}
			
		}
	public:
		StaticLinkList()
		{
			for (int count = 0; count < N; count++)
			{
				m_used[count] = 0;
			}	
		}
		int capacity()
		{
			return N;
		}
		
		~StaticLinkList()
		{
			this->clear();//�����õ�ǰ���еĶ�����ϻ�������
		}
	};
}

#endif