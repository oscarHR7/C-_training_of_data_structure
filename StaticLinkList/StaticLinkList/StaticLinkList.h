#ifndef _STATICLINKLIST_H_
#define _STATICLINKLIST_H_

#include "../LinkList/LinkList.h"


namespace DTLib
{
	template
	<typename T, int N >//整型模版参数定义预留空间大小使用
	class StaticLinkList : public LinkList<T>
	{
	protected:
		typedef typename LinkList<T>::Node Node; //typename 指明Node为一个类而不是变量 因为此类中包含了T

		struct SNode : public Node
		{
			void* operator new(unsigned int size, void* loc)//重载构造函数
			{
				(void)size;//size未使用的暴力处理方式
				return loc;
			}
		};

		unsigned char m_space[sizeof(SNode)*N];//预留内存
		int m_used[N];//记录对应N处是否已经存在数据若存在则变为1

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
			SNode* psn = dynamic_cast<SNode*>( pn );//父类指针转换为子类
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
			this->clear();//仅调用当前类中的定义符合基本需求
		}
	};
}

#endif