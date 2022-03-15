#include<iostream>
#include"StaticArray.h"
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"

using namespace std;
using namespace DTLib;

int main()
{
	StaticArray<int, 5>staticarray1;
	for(int i = 0;i< staticarray1.length();i++)
	{
		staticarray1[i] = i * i;
	}
	for (int i = 0; i < staticarray1.length(); i++)
	{
		cout<<staticarray1[i]<<endl ;
	}
	StaticArray<int, 5>staticarray2(staticarray1);
	cout << endl;
	cout << endl;
	staticarray2 = staticarray1;
	for (int number = 0; number < staticarray2.length(); number++)
	{
		cout << staticarray2[number]<< endl;
	}
	cout << endl;
	cout << endl;
	for (int number = 0; number < staticarray1.length(); number++)
	{
		staticarray1.set(number, number);
		cout<< staticarray1[number]<<endl;
	}
	
	return 0;
}