#include"top_object.h"
#include<cstdlib>//malloc函数的头文件
//#include<iostream>
//using namespace std;
using namespace DTLib;
void* top_object::operator new(unsigned int size) throw()
{
	//cout << "replace_operator_new"<<endl;//测试new重载是否成功
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