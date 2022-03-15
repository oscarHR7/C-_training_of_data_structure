#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include"../top_object/top_object.h"
namespace DTLib
{
	
#define THROW_EXCEPTION(ex,messages) (throw ex(messages, __FILE__, __LINE__))//宏自动填上文件名和行号

class Exception : public top_object //此处仅仅是异常的父类定义具体异常定义看后续
{
protected:
	char* m_message;//存储异常信息
	char* m_location;//存储异常的地址
	void init(const char* message, const char* file, int line);//初始化构造函数逻辑差不多采用辅助函数初始化
public:
	Exception(const char* message);
	Exception(const char* file,int line);
	Exception(const char* message, const char* file, int line);

	Exception(const Exception& exception);
	Exception& operator = (const Exception& exception);//从构造函数不难看出在赋值过程中为深拷贝

	virtual const char* message() const;
	virtual const char* location() const;

	virtual ~Exception();//纯虚函数代表当前类为抽象类,原则上来讲纯虚函数留给子类来实现，但是对于析构函数而言不论是否为纯虚都要实现
};

class ArithmeticException : public Exception
{
public:
	ArithmeticException():Exception(0){}
	ArithmeticException(const char* message):Exception(message){}
	ArithmeticException(const char* file, int line):Exception(file,line){}
	ArithmeticException(const char* message, const char* file, int line) :Exception(message,file,line) {}

	ArithmeticException(const ArithmeticException& exception):Exception(exception){}
	ArithmeticException& operator = (const ArithmeticException& exception)  
	{
		Exception::operator = (exception);
		return *this;//此处的return是否有存在的必要
	}
};


class NullPointerException : public Exception
{
public:
	NullPointerException() :Exception(0) {}
	NullPointerException(const char* message) :Exception(message) {}
	NullPointerException(const char* file, int line) :Exception(file, line) {}
	NullPointerException(const char* message, const char* file, int line) :Exception(message, file, line) {}

	NullPointerException(const NullPointerException& exception) :Exception(exception) {}
	NullPointerException& operator = (const NullPointerException& exception)
	{
		Exception::operator = (exception);
		return *this;//此处的return是否有存在的必要
	}
};


class IndexOutOfBoundsException : public Exception
{
public:
	IndexOutOfBoundsException() :Exception(0) {}
	IndexOutOfBoundsException(const char* message) :Exception(message) {}
	IndexOutOfBoundsException(const char* file, int line) :Exception(file, line) {}
	IndexOutOfBoundsException(const char* message, const char* file, int line) :Exception(message, file, line) {}

	IndexOutOfBoundsException(const IndexOutOfBoundsException& exception) :Exception(exception) {}
	IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException& exception)
	{
		Exception::operator = (exception);
		return *this;//此处的return是否有存在的必要
	}
};



class NoEnoughMemoryException : public Exception
{
public:
	NoEnoughMemoryException() :Exception(0) {}
	NoEnoughMemoryException(const char* message) :Exception(message) {}
	NoEnoughMemoryException(const char* file, int line) :Exception(file, line) {}
	NoEnoughMemoryException(const char* message, const char* file, int line) :Exception(message, file, line) {}

	NoEnoughMemoryException(const NoEnoughMemoryException& exception) :Exception(exception) {}
	NoEnoughMemoryException& operator = (const NoEnoughMemoryException& exception)
	{
		Exception::operator = (exception);
		return *this;//此处的return是否有存在的必要
	}
};


class InvalidParameterException : public Exception
{
public:
	InvalidParameterException() :Exception(0) {}
	InvalidParameterException(const char* message) :Exception(message) {}
	InvalidParameterException(const char* file, int line) :Exception(file, line) {}
	InvalidParameterException(const char* message, const char* file, int line) :Exception(message, file, line) {}

	InvalidParameterException(const InvalidParameterException& exception) :Exception(exception) {}
	InvalidParameterException& operator = (const InvalidParameterException& exception)
	{
		Exception::operator = (exception);
		return *this;//此处的return是否有存在的必要
	}
};


class InvalidOperationException : public Exception
{
public:
	InvalidOperationException() :Exception(0) {}
	InvalidOperationException(const char* message) :Exception(message) {}
	InvalidOperationException(const char* file, int line) :Exception(file, line) {}
	InvalidOperationException(const char* message, const char* file, int line) :Exception(message, file, line) {}

	InvalidOperationException(const InvalidOperationException& exception) :Exception(exception) {}
	InvalidOperationException& operator = (const InvalidOperationException& exception)
	{
		Exception::operator = (exception);
		return *this;//此处的return是否有存在的必要
	}
};


}


#endif
