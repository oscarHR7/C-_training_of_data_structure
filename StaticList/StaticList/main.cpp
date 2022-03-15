#include<iostream>
#include "StaticList.h"
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"//����������Ͷ���ֿ���.h��.cpp��ʵ��ʱ�򣬲��ɱ�����ڵ����л���ִ�������ʶ�ֱ����.h�����������Ϊ�ȶ�

using namespace std;
using namespace DTLib;

int main()
{
	StaticList<int, 5>l;
	for (int number = 0; number < l.capacity(); number++)
	{
		l.insert(number, number);
	}
	try
	{
	 l[5] = 0;
     }
	catch (const Exception& exception)
	{
		cout<<exception.message()<<endl ;
		cout << exception.location() << endl;
	}
	cout<< l.length() <<endl;
	return 0;
}

