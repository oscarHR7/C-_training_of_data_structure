#include<iostream>
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"
#include"LinkList.h"

using namespace std;
using namespace DTLib;

class Test :public top_object
{
	int i;
public:
	Test(int v = 0)
	{
		i = v;
	}
	bool operator ==(const Test& object)const
	{
		return (i == object.i);
	}
};

int main()
{
	LinkList<int> list;


	/*�������������ʱ�临�Ӷ�ΪO(n)*/
/*
	for (int count = 0; count < 5; count++)
	{
		list.insert(count);
	}

	for (list.move(0);!list.end();list.next())//����������
	{
		cout << list.current() <<endl;
	}
*/



	/*���������ݲ���*/
/*	
	Test t1(1);
	Test t2(2);
	Test t3(3);//���ڽṹ��Ҫ���� == ���ع��������Զ��㸸����и���
	
	list.insert(t1);
	list.insert(t2);
	list.insert(t3);

	cout << list.find(t2) << endl;
*/
/*������Ա��������*/
	/*
	for (int count = 0; count < 5; count++)
	{
		list.insert(count);
	}
		cout<< list.length() << endl;

		cout << endl;

	for (int count = 0; count < list.length(); count++)
	{
		cout<< list.get(count)<< endl;
	}

	cout << endl;

	cout<<list.find(3)<<endl;

	cout << endl;

	list.remove(3);
	for (int count = 0; count < list.length(); count++)
	{
		cout << list.get(count) << endl;
	}
	*/
	return 0;
}


