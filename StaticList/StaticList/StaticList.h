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
		this->m_array = m_space;//thisָ��ָ��ǰ�Ķ��󣬶���ǰ����̳и�������thisָ���൱�ڿ���ָ��̳и���ı���
		this->m_length = 0;//�������this��ô�����޷��ҵ������еĳ�Ա��������Ϊ���캯���ǶԵ�ǰ����в���
	}
	int capacity()const
	{
		return N;
	}

};
}
#endif