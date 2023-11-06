#include "BankingSystemV01.h"

Account *accArr[100];	// Account 저장을 위한 배열
int accNum = 0;		// 저장된 Account 수

void Bankingmain(void) {

	int choice;

	while (1) {
		ShowMenu();
		cout << "선택 :";
		cin >> choice;
		 //cout << "선택 : "; cin >> choice;
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
	cout << "1. 개좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;

}

void MakeAccount(void) {

	int id;
	char name[NAME_LANG];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID:  "; cin >>id;
	cout << "이 름:  "; cin >> name;
	cout << "입금액:  "; cin >> balance;
	cout <<endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {

	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID:  "; cin >> id;
	cout << "입금액:  "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccId() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;

}

void WithdrawMoney(void) {

	int money;
	int id;

	cout << "[출 금]" << endl;
	cout << "계좌ID:  "; cin >> id;
	cout << "출금액:  "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccId() == id) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl;
				return;
			}

			cout << "출금완료" << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다" << endl << endl;

}

void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}