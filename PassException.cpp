#include "PassException.h"

void PassException::Divide(int num1, int num2)
{
	if (num2 == 0)
	{
		throw num2;
	}
	cout << "�������� �� : " << num1/num2 << endl;
	cout << "�������� ������ : " << num1%num2 << endl;
}

