#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H___

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int accID, int money, String name, int rate, int special)
		:NormalAccount(accID, money, name, rate), specialRate(special) {}
	virtual void Deposit(int money)
	{
		if (money < 0)
		{
			throw MinusException(money);
		}
		NormalAccount::Deposit(money);	// 원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0)); // 특별이자 추가
	}
};


#endif
