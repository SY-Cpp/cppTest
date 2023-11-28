#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int ID, int money, String name)
	:accID(ID), balance(money)
{
	cusName = name;

}
/*
Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
*/
/*
Account& Account::operator=(const Account& ref) 
{
	accID = ref.accID;
	balance = ref.balance;
	delete[]cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);

	return *this;
}

Account::~Account() {
	delete[]cusName;
}
*/

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int money)
{
	if(money < 0)
	{
		throw MinusException(money);
	}
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money) {
		return 0;
	}
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ ¸§: " << cusName << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
}
