
/*
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
*/
#include "TestFunctor.h"
//#include "Functor.cpp"
/*
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
*/

int main(void) {

	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9)) << endl;

	/*
	AccountHandler manager;
	int choice;

	while (1) 
	{
		manager.ShowMenu();
		cout << "¼±ÅÃ: "; cin >> choice;

		switch (choice) 
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	*/


	return 0;
}
