#include<iostream>
#include"Exception.h"
using namespace std;
using namespace DTLib;

int main()
{
/*�����Ƿ�̳��˶��㸸��ɹ�������new��delete������*/
	//ArithmeticException* sp = new ArithmeticException();
/*�����쳣��׽*/
	try
	{
		THROW_EXCEPTION(ArithmeticException, "test");
	}
	catch (const ArithmeticException& exception)
	{
		cout << "catch ArithmeticException" << endl;
		cout << exception.message() << endl;
		cout << exception.location() << endl;
	}
	catch (const Exception& exception)
	{
		cout<<"catch Exception" << endl;
		cout << exception.message() << endl;
		cout << exception.location() << endl;
	}


	return 0;
}