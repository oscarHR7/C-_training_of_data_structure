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
	List& operator = (const List&);//对于容器类的数据结构一般不采用这两种赋值构造方式
public:
	List(){}//由于protested中存在了构造函数那么将不会再有默认构造函数提供，故而要自己再次手写一个
	virtual bool insert(const T& Data_element) = 0;//重载函数，直接默认为在尾端插入
	virtual bool insert(int i,const T& Data_element) = 0;
	virtual bool remove(int i) = 0;

	virtual bool set(int i,const T& Data_element) = 0;
	virtual bool get(int i,T& Data_element) const = 0;

	virtual int length() const = 0;
	virtual void clear() = 0;
};
}






#endif
