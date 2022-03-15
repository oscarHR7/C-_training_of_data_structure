#include<iostream>
#include"Exception.h"
using namespace std;
using namespace DTLib;

int main()
{
/*测试是否继承了顶层父类成功重载了new和delete操作符*/
	//ArithmeticException* sp = new ArithmeticException();
/*测试异常捕捉*/
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