#include<iostream>
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"
#include"StaticLinkList.h"

using namespace std;
using namespace DTLib;


int main()
{
	StaticLinkList<int,5> list;


	/*�������������ʱ�临�Ӷ�ΪO(n)*/

	for (int count = 0; count < 5; count++)
	{
		list.insert(count, count);
	}
	
	list.remove(2);

	for (list.move(0);!list.end();list.next())//����������
	{
		cout << list.current() <<endl;
	}

	return 0;
}


