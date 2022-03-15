#include<iostream>
#include "../top_object/top_object.cpp"
#include"SmartPointer.h"//头文件的调用注意顺序性SmartPointer基于top_object产生故而必须先进行对top的包含
using namespace std;
using namespace DLTib;

class Test : public top_object
{
public:
	Test()
	{
		cout << "hello,world" << endl;
	}
	~Test()
	{
		cout << "goodbye,world" << endl;
	}
};
int main()
{
	SmartPointer<Test> mp1 =new Test();

	return 0;
}