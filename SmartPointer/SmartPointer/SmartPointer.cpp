#include<iostream>
#include "../top_object/top_object.cpp"
#include"SmartPointer.h"//ͷ�ļ��ĵ���ע��˳����SmartPointer����top_object�����ʶ������Ƚ��ж�top�İ���
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