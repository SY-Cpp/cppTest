#include "PassException.h"

void PassException::Divide(int num1, int num2)
{
	if (num2 == 0)
	{
		throw num2;
	}
	cout << "³ª´°¼ÀÀÇ ¸ò : " << num1/num2 << endl;
	cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö : " << num1%num2 << endl;
}

