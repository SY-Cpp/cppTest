#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class MinusException
{
private:
	int exval; 
public:
	MinusException(int val) : exval(val) {}

	void ShowExceptionInfo(void) const
	{
		cout << "��(��)�ݾ�" << exval << "�� ��ȿ���� �ʽ��ϴ�." << endl;
	}
};

class InsuffException
{
private:
	int balance;		// ���� �ݾ�
	int reqval;			// ��� �䱸��
public:
	InsuffException(int val, int req)
		:balance(val), reqval(req)
	{}
	void ShowException() const
	{
		cout << "�ܾ׿��� " << reqval - balance << "��(��) �����մϴ�" << endl;
	}
};

#endif