#include "BankingSystemV01.h"

Account *accArr[100];	// Account ������ ���� �迭
int accNum = 0;		// ����� Account ��

void Bankingmain(void) {

	int choice;

	while (1) {
		ShowMenu();
		cout << "���� :";
		cin >> choice;
		 //cout << "���� : "; cin >> choice;
		cout << endl;

		switch (choice) {
		case BANK_MENU::MAKE:
			MakeAccount();
			break;
		case BANK_MENU::DEPOSIT:
			DepositMoney();
			break;
		case BANK_MENU::WITHDRAW:
			WithdrawMoney();
			break;
		case BANK_MENU::INQUIRE:
			ShowAllAccInfo();
			break;
		case BANK_MENU::EXIT:
			for (int i = 0; i < accNum; i++) {
				delete accArr[i];
			}
		default:
			cout << "Illegal selection" << endl;
		}

	}
}

void ShowMenu(void) {
	cout << "---- Menu ----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

}

void MakeAccount(void) {

	int id;
	char name[NAME_LANG];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID:  "; cin >>id;
	cout << "�� ��:  "; cin >> name;
	cout << "�Աݾ�:  "; cin >> balance;
	cout <<endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {

	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID:  "; cin >> id;
	cout << "�Աݾ�:  "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccId() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;

}

void WithdrawMoney(void) {

	int money;
	int id;

	cout << "[�� ��]" << endl;
	cout << "����ID:  "; cin >> id;
	cout << "��ݾ�:  "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccId() == id) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl;
				return;
			}

			cout << "��ݿϷ�" << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;

}

void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}