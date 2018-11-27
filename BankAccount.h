#pragma once
#include"headers.h"

class BankAccount :
	public Account
{
public:
	BankAccount();
	double getCashBalance();
	void displayAccountBalance();
	void depositMoney(double money);
	void withdrawMoney(double money);
	void printHistory();
};

