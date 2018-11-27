#pragma once
#include"List_bank.h"
class Account
{
public:
	Account();
	virtual List_bank* getBankAccount() = 0;
protected:
	double cashBalance;
	List_bank* bankAcnt;
};

