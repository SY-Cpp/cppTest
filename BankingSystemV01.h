//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LANG = 20;

void ShowMenu(void);		// �޴����
void MakeAccount(void);		// ���°��� �Լ�
void DepositMoney(void);	// ��	��
void WithdrawMoney(void);	// ��	��
void ShowAllAccInfo(void);	// �ܾ���ȸ
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
	int accID;		// ���¹�ȣ
	int balance;	// ��	��
	char* cusName;	// ���̸�

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

	int Withdraw(int money) {	// ��ݾ� ��ȯ, ���� �� 0 ��ȯ
		if (balance == 0) {
			return 0;
		}

		balance -= money;
		return money;
	}

	void ShowAccInfo() {
		cout << "����ID:  " << accID << endl;
		cout << "�� ��:  " << cusName << endl;
		cout << "�� ��:  " << balance << endl;

	}

	~Account() {
		delete[]cusName;
	}
};