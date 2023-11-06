#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H___

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int accID, int money, char* name, int rate, int special)
		:NormalAccount(accID, money, name, rate), specialRate(special) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);	// ���ݰ� �����߰�
		Account::Deposit(money * (specialRate / 100.0)); // Ư������ �߰�
	}
};


#endif
