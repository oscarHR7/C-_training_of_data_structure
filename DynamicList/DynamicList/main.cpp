#include<iostream>
#include"../SeqList/SeqList.h"
#include "DynamicList.h"
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"//����������Ͷ���ֿ���.h��.cpp��ʵ��ʱ�򣬲��ɱ�����ڵ����л���ִ�������ʶ�ֱ����.h�����������Ϊ�ȶ�

using namespace std;
using namespace DTLib;

int main()
{



	/*DynamicList<int>Dynamic_arry(5);
	for (int number = 0; number < Dynamic_arry.capacity(); number++)
	{
	//	Dynamic_arry[number] = number;���Ա�����Ȳ���Ԫ�ز���ʹ��[]����Ԫ��
		Dynamic_arry.insert(number, number);
	}
	for (int number = 0; number < Dynamic_arry.capacity(); number++)
	{
		cout<< Dynamic_arry [number]<<endl;
	}
	try
	{
		Dynamic_arry[5] = 0;
	}
	catch (const Exception& exception)
	{
		cout << exception.message() << endl;
		cout << exception.location() << endl;

		Dynamic_arry.resize(10);
		Dynamic_arry.insert(5,10);
		cout << Dynamic_arry[5] << endl;
	}*/

	/*
����insert�����Ĵ���ʵ��
DynamicList<int>Dynamic_arry(5);
for (int number = 0; number < Dynamic_arry.capacity(); number++)
{
		Dynamic_arry.insert( number);
}

for (int number = 0; number < Dynamic_arry.capacity(); number++)
{
	cout<<Dynamic_arry[number]<<endl;
}*/
	return 0;
}

//���Ա��ṩ���������ز�������ͨ�������ܹ���ݷ���Ļ�ȡĿ��λ�ô�������Ԫ�أ��ھ���ʹ�����������鵫�Ǳ��ʲ�ͬ