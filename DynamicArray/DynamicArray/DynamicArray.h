#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include"../Array/Array.h"
#include"../Exception/Exception.h"
namespace DTLib
{

template
<typename T>
class DynamicArray : public Array<T>
{
protected:
	int m_length;

	T* copy(T* array, int len, int newlen)
	{
		T* ret = new T[newlen];
		if (ret != NULL)
		{
			int size = len >= newlen ? newlen : len;
			for (int i = 0;i<size; i++)
			{
				ret[i] = array[i];
			}
		}
		return ret;
	}

	void update(T* array, int length)
	{
		if (array != NULL)
		{
			T* temp = this->m_array;
			this->m_array = array;
			this->m_length = length;
			delete[]temp;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory to update dynamicarray fail...");
		}
	}

	void data(T* array, int length)
	{
		if (array != NULL)
		{
			T* temp = this->m_array;
			this->m_array = array;
			this->m_length = length;
			delete[]temp;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory updata dynamicarray fail...");
		}
	}
	
	void init(T* array, int length)
	{
		if (array != NULL)
		{
			this->m_array = array;
			this->m_length = length;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "No memory init dynamicarray fail...");
		}
	}

public:
	DynamicArray(int length)
	{
		/*优化代码*/
		init(new T [length], length);
		/*原始代码*/
		/*this->m_array = new T[length];
		if (this->m_array != NULL)
		{
			this->m_length = length;
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException,"creat dynamicarray fail...");
		}*/
	}

	DynamicArray(DynamicArray <T>& obj)//拷贝构造函数和等于号的重载是有区别的，拷贝构造意味着当前对象将要在此函数中产生，而等于重载是当前对象已经产生需要修改一些参数而已
	{
		T* array = copy(obj.m_array, obj.m_length, obj.m_length);
		init(array, obj.m_length);
		
		/*原始代码*/
		/*this->m_array = new T [obj.m_length];
		if (this->m_array != NULL)
		{
			
			this->m_length = obj.m_length;
			for (int i = 0; i < this->m_length; i++)
			{
				this->m_array[i] = obj.m_array[i];
			}
		}
		else
		{
			THROW_EXCEPTION(NoEnoughMemoryException, "copy_creat dynamicarray fail...");
		}*/
	}
	DynamicArray<T>& operator = (DynamicArray <T>& obj)//避免对象的自赋值,通过创建好一个新的数组再赋给自己来实现相关解决的问题
	{
		if (this != &obj)
		{
			/*优化方案代码*/
			T* array = copy(obj.m_array, obj.m_length, obj.m_length);
			update(array, obj.m_length);
		}
			/*原始代码*/
		/*	T* array = new T[obj.m_length];
			if (array != NULL)
			{
				for (int i = 0; i < obj.m_length; i++)
				{
					array[i] = obj.m_array[i];
				}
			
				T* temp = this->m_array;
				
				this->m_array = array;
				this->m_length = obj.m_length;

				delete[]temp;

			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "copy_memory dynamicarray fail...");
			}*/
			
			return *this;
			
		
	}

	int length()const
	{
		return (this->m_length);
	}

	void resize(int length)
	{
		if (length != m_length)
		{
			/*优化代码*/
			T* array = copy(this->m_array, this->m_length, length);
			update(array, length);


			/*原始代码*/
			/*
			T* array = new T [length];
			if (array != NULL)
			{
				int size = m_length <= length ? m_length : length;//关键点
				for (int i = 0; i < size; i++)
				{
					array[i] = this->m_array[i];
				}
				T* temp = this->m_array;
				this->m_array = array;
				this->m_length = length;
				delete[]temp;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "no resize memory dynamicarray fail...");
			}*/
		}
	}

	~DynamicArray()
	{
		delete[](this->m_array);
	}
};

}



#endif
