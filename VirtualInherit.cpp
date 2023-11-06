#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base
{
public:
	MiddleDerivedOne() : Base() {
		cout << "MiddlerDerviedOne Constructor" << endl;
	}
	void MiddleFuncOne() {
		SimpleFunc();
		cout << "MiddleFuncOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public Base
{
public:
	MiddleDerivedTwo() : Base() {
		cout << "MiddleDerivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleFuncTwo" << endl;
	}
};

class LastDervied : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDervied() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerived Constructor" << endl;
	}
	void ComplexFunc() 
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};