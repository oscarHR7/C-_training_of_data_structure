#include<iostream>
#include"DynamicArray.h"
#include"../top_object/top_object.cpp"
#include"../Exception/Exception.cpp"

using namespace std;
using namespace DTLib;

int main()
{
	DynamicArray<int>dynamicArray1(5);
	for(int i = 0;i< dynamicArray1.length();i++)
	{
		dynamicArray1[i] = i * i;
	}
	for (int i = 0; i < dynamicArray1.length(); i++)
	{
		cout<< dynamicArray1[i]<<endl ;
	}
		cout << endl;
		cout << endl;
	DynamicArray<int>dynamicArray2(10);
	dynamicArray2 = dynamicArray1;
	for (int i = 0; i < dynamicArray2.length(); i++)
	{
		cout << dynamicArray2[i] << endl;
	}
		cout << endl;
		cout << endl;
		
		dynamicArray2.resize(10);
		for (int i = 0; i < dynamicArray2.length(); i++)
		{
			cout << dynamicArray2[i] << endl;
		}

		cout << endl;
		cout << endl;

		dynamicArray2.resize(3);
		for (int i = 0; i < dynamicArray2.length(); i++)
		{
			cout << dynamicArray2[i] << endl;
		}


	
	return 0;
}