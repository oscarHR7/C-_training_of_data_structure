#include<iostream>
#include"../SeqList/SeqList.h"
#include "DynamicList.h"
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"//当类的声明和定义分开在.h和.cpp中实现时候，不可避免的在调用中会出现此类情况故而直接在.h定义加声明更为稳定

using namespace std;
using namespace DTLib;

int main()
{



	/*DynamicList<int>Dynamic_arry(5);
	for (int number = 0; number < Dynamic_arry.capacity(); number++)
	{
	//	Dynamic_arry[number] = number;线性表必须先插入元素才能使用[]访问元素
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
重载insert操作的代码实验
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

//线性表提供了数组重载操作符，通过重载能够快捷方便的获取目标位置处的数据元素，在具体使用上类似数组但是本质不同