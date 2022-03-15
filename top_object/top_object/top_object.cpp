#include"top_object.h"
#include<cstdlib>//malloc函数的头文件

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
bool top_object::operator == (const top_object& object)
{
	return (this == &object);
}

bool top_object::operator !=(const top_object& object)
{
	return (this != &object);
}
top_object::~top_object()
{

}