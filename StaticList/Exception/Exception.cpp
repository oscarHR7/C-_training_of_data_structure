#include "Exception.h"
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;

namespace DTLib
{ 

void Exception::init(const char* message, const char* file, int line)
{
	
	m_message = _strdup(message);//不可用直接使用m_message=message因为不确定message的生命周期
	
	if (file != NULL)
	{
		char sl[16] = {0};
		
		_itoa(line,sl,10);

		m_location = static_cast<char*> (malloc(strlen(sl) + strlen(file) + 2));//加2是为了拼接一个：和字符串的最后一个结束符
		if (m_location != NULL)
		{
			m_location = strcpy(m_location, file);
			m_location = strcat(m_location, ":");
			m_location = strcat(m_location, sl);
		}
	}
	else
	{
		m_location = NULL;
	}
}
 Exception::Exception(const char* message)
{
	 init(message,NULL,0);
}
 Exception::Exception(const char* file, int line)
 {
	 init(NULL, file, line);
 }
 Exception::Exception(const char* message, const char* file, int line)
 {
	 init(message, file, line);
 }

 Exception::Exception(const Exception& exception)
 {
	 m_message = _strdup(exception.m_message);
	 m_location = _strdup(exception.m_location);//拷贝构造需要保证内部指针指向的是一段独立生命周期的堆空间
 }
 Exception& Exception::operator = (const Exception& exception)//赋值函数切记不可自赋值
 {
	 if(this != &exception)
	 { 
		 free(m_message);//重载赋值操作符必须释放原来有的指向
		 free(m_location);
	     m_message = _strdup(exception.m_message);
	     m_location =_strdup(exception.m_location);//拷贝构造需要保证内部指针指向的是一段独立生命周期的堆空间
	 }
	 return *this;
 }


 const char* Exception::message() const
 {
	 return m_message;
 }
 const char* Exception::location() const
 {
	 return m_location;
 }

 Exception:: ~Exception()
 {
	 free(m_message);
	 free(m_location);
 }



}