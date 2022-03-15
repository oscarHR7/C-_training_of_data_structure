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


	/*遍历单链表测试时间复杂度为O(n)*/
/*
	for (int count = 0; count < 5; count++)
	{
		list.insert(count);
	}

	for (list.move(0);!list.end();list.next())//遍历单链表
	{
		cout << list.current() <<endl;
	}
*/



	/*类类型数据测试*/
/*	
	Test t1(1);
	Test t2(2);
	Test t3(3);//对于结构体要考虑 == 的重构操作符对顶层父类进行改造
	
	list.insert(t1);
	list.insert(t2);
	list.insert(t3);

	cout << list.find(t2) << endl;
*/
/*基础成员函数测试*/
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


