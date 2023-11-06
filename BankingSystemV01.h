//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LANG = 20;

void ShowMenu(void);		// 메뉴출력
void MakeAccount(void);		// 계좌개설 함수
void DepositMoney(void);	// 입	금
void WithdrawMoney(void);	// 출	금
void ShowAllAccInfo(void);	// 잔액조회
void Bankingmain(void);

enum BANK_MENU {
	MAKE = 1
	, DEPOSIT
	, WITHDRAW
	, INQUIRE
	, EXIT
};

enum Test_ENUM {
	CLERK, SENIOR, ASSIST, MANAGER
};
class Account {
private:
	int accID;		// 계좌번호
	int balance;	// 잔	액
	char* cusName;	// 고객이름

public:
	Account(int ID, int money, char* name)
		:accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	int GetAccId() { return accID; }

	void Deposit(int money) {
		balance += money;
	}

	int Withdraw(int money) {	// 출금액 반환, 부족 시 0 반환
		if (balance == 0) {
			return 0;
		}

		balance -= money;
		return money;
	}

	void ShowAccInfo() {
		cout << "계좌ID:  " << accID << endl;
		cout << "이 름:  " << cusName << endl;
		cout << "잔 액:  " << balance << endl;

	}

	~Account() {
		delete[]cusName;
	}
};