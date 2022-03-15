#include<iostream>
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"
#include"CircleList.h"
//约瑟夫问题的求解
using namespace std;
using namespace DTLib;

void order(int person_number, int begin_number, int die_order)
{
	CircleList<int> cl;
	for (int count = 1; count <= person_number; count++)
	{
		cl.insert(count);
	}

	cl.move(begin_number - 1, die_order - 1);

	for(int i = 0; i<2 ;i++)
	{
		cl.next();
		cout << cl.current()<< endl;
		cl.remove(cl.find(cl.current()));
	}
}




int main()
{
	LinkList<int>c;
	for (int count = 1; count <= 5; count++)
	{
		c.insert(count);
	}
	for (int count = 0; count < c.length(); count++)
	{
		cout<<c.get(count)<<endl;
	}
	
	for (int count = 1; count < c.length(); count++)
	{
		 c.remove(count) ;
	} 
	for (int count = 0; count < c.length(); count++)
	{
		cout << c.get(count) << endl;
	}
	return 0;
}

