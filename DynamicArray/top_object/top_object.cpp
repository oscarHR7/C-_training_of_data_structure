#include"top_object.h"
#include<cstdlib>//malloc������ͷ�ļ�

using namespace DTLib;
void* top_object::operator new(unsigned int size) throw()
{
	return malloc(size);
}
void top_object::operator delete(void* p)
{
	delete(p);
}
void* top_object::operator new[](unsigned int size) throw()
{
	return malloc(size);
}
void  top_object::operator delete[](void* p)
{
	delete(p);
}
top_object::~top_object()
{

}