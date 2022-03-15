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
	
	m_message = _strdup(message);//������ֱ��ʹ��m_message=message��Ϊ��ȷ��message����������
	
	if (file != NULL)
	{
		char sl[16] = {0};
		
		_itoa(line,sl,10);

		m_location = static_cast<char*> (malloc(strlen(sl) + strlen(file) + 2));//��2��Ϊ��ƴ��һ�������ַ��������һ��������
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
	 m_location = _strdup(exception.m_location);//����������Ҫ��֤�ڲ�ָ��ָ�����һ�ζ����������ڵĶѿռ�
 }
 Exception& Exception::operator = (const Exception& exception)//��ֵ�����мǲ����Ը�ֵ
 {
	 if(this != &exception)
	 { 
		 free(m_message);//���ظ�ֵ�����������ͷ�ԭ���е�ָ��
		 free(m_location);
	     m_message = _strdup(exception.m_message);
	     m_location =_strdup(exception.m_location);//����������Ҫ��֤�ڲ�ָ��ָ�����һ�ζ����������ڵĶѿռ�
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