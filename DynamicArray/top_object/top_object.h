#ifndef _TOP_OBJECT_H_
#define _TOP_OBJECT_H_

namespace DTLib
{
	class top_object//newһ��ʧ�ܿ��ܷ��ؿ�ָ�����һ���쳣Ϊ�� ͳһnew��Ϊ����˶���
	{
	public:
		void* operator new(unsigned int size) throw();//������ʧ�ܵ�ʱ��ֻ���׳�һ��NULL�������׳��κ��쳣
		void  operator delete(void* p);
		void* operator new[](unsigned int size) throw();
		void  operator delete[](void* p);
		virtual ~top_object() = 0;//��̬����ʶ��
	};
}




#endif