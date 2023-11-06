#include <iostream>
#include <cstring>

using namespace std;

class First
{
public:
	void MyFunction()
	{
		cout << "FirstFunction" << endl;
	}
	virtual void MyVirtualFunction() 
	{
		cout << "FirstVirtualFunction" << endl;
	}
};

class Second : public First
{
public:
	void MyFunction()
	{
		cout << "SecondFunction" << endl;
	}
	
	virtual void MyVirtualFunction()
	{
		cout << "SecondVirtualFunction" << endl;
	}
};

class Third : public Second
{
public:
	void MyFunction()
	{
		cout << "ThirdFunction" << endl;
	}
	virtual void MyVirtualFunction()
	{
		cout << "ThirdVirtualFunction" << endl;
	}
};
