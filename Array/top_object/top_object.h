#ifndef _TOP_OBJECT_H_
#define _TOP_OBJECT_H_

namespace DTLib
{
	class top_object//new一旦失败可能返回空指针或者一个异常为了 统一new行为才如此定义
	{
	public:
		void* operator new(unsigned int size) throw();//在申请失败的时候只会抛出一个NULL而不会抛出任何异常
		void  operator delete(void* p);
		void* operator new[](unsigned int size) throw();
		void  operator delete[](void* p);
		virtual ~top_object() = 0;//动态类型识别
	};
}




#endif