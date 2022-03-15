#ifndef _ARRAY_H_
#define _ARRAY_H_
#include"../top_object/top_object.h"
#include"../Exception/Exception.h"
namespace DTLib
{

	template
	<typename T>
	class Array : public top_object
	{
	protected:
		T* m_array;
	public:
		virtual bool set(int i,const T& e)
		{
			bool ret = (i >= 0 && i < length());
				if (ret)
				{
					m_array[i] = e;
				}
			return ret;
		}
		virtual bool get(int i,   T& e)
		{
			bool ret = (i >= 0 && i <  length());
				if (ret)
				{
					e = m_array[i];
				}
			return ret;
		}

		T& operator [](int i)
		{
			bool ret = (i >= 0 && i < length());
				if (ret)
				{
					return  m_array[i];
				}
				else
				{
					THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid...");//弥补原生数组的缺点
				}

		}

		T  operator[](int i)const
		{
			return (const_cast<Array<T>&>(*this))[i];
		}

		virtual int length()const = 0;//此类为抽象类仅能用来被继承
	};

}

#endif
