#include<iostream>
#include "StaticList.h"
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"//当类的声明和定义分开在.h和.cpp中实现时候，不可避免的在调用中会出现此类情况故而直接在.h定义加声明更为稳定

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

