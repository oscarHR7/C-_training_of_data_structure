#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include"../top_object/top_object.h"
namespace DTLib
{
	
#define THROW_EXCEPTION(ex,messages) (throw ex(messages, __FILE__, __LINE__))//���Զ������ļ������к�

class Exception : public top_object //�˴��������쳣�ĸ��ඨ������쳣���忴����
{
protected:
	char* m_message;//�洢�쳣��Ϣ
	char* m_location;//�洢�쳣�ĵ�ַ
	void init(const char* message, const char* file, int line);//��ʼ�����캯���߼������ø���������ʼ��
public:
	Exception(const char* message);
	Exception(const char* file,int line);
	Exception(const char* message, const char* file, int line);

	Exception(const Exception& exception);
	Exception& operator = (const Exception& exception);//�ӹ��캯�����ѿ����ڸ�ֵ������Ϊ���

	virtual const char* message() const;
	virtual const char* location() const;

	virtual ~Exception();//���麯������ǰ��Ϊ������,ԭ�����������麯������������ʵ�֣����Ƕ��������������Բ����Ƿ�Ϊ���鶼Ҫʵ��
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
		return *this;//�˴���return�Ƿ��д��ڵı�Ҫ
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
		return *this;//�˴���return�Ƿ��д��ڵı�Ҫ
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
		return *this;//�˴���return�Ƿ��д��ڵı�Ҫ
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
		return *this;//�˴���return�Ƿ��д��ڵı�Ҫ
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
		return *this;//�˴���return�Ƿ��д��ڵı�Ҫ
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
		return *this;//�˴���return�Ƿ��д��ڵı�Ҫ
	}
};


}


#endif
