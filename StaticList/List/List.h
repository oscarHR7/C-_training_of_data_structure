#ifndef _LIST_H_
#define _LIST_H_

#include"../top_object/top_object.h"

namespace DTLib
{
template
<typename T>
class List:public top_object
{
protected:
	List(const List&);
	List& operator = (const List&);//��������������ݽṹһ�㲻���������ָ�ֵ���췽ʽ
public:
	List(){}//����protested�д����˹��캯����ô����������Ĭ�Ϲ��캯���ṩ���ʶ�Ҫ�Լ��ٴ���дһ��
	virtual bool insert(const T& Data_element) = 0;//���غ�����ֱ��Ĭ��Ϊ��β�˲���
	virtual bool insert(int i,const T& Data_element) = 0;
	virtual bool remove(int i) = 0;

	virtual bool set(int i,const T& Data_element) = 0;
	virtual bool get(int i,T& Data_element) const = 0;

	virtual int length() const = 0;
	virtual void clear() = 0;
};
}






#endif
