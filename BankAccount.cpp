#include"headers.h"

BankAccount::BankAccount()
{
	cashBalance = 0.0;
	bankAcnt = new List_bank();
}

double BankAccount::getCashBalance()
{
	bankAcnt->read();
	cashBalance = bankAcnt->getTail()->balance;
	return cashBalance;
}

void BankAccount::displayAccountBalance()
{
	cout << "You have $" << getCashBalance() << "in your bank account." << endl;
}

void BankAccount::depositMoney(double money)
{
	cashBalance += money;

	char tmp[15] = "Deposit";
	char dateTmp[20] = "";
	Banklog* p = new Banklog();

	time_t nowtime;
	nowtime = time(NULL); 
	strftime(dateTmp, 20, "%m/%d/%Y", localtime(&nowtime));

	bankAcnt->pushback(tmp, money, cashBalance, dateTmp);
	
	bankAcnt->write();
}

void BankAccount::withdrawMoney(double money)
{
	cashBalance -= money;

	char tmp[15] = "Withdrawal";
	char dateTmp[20] = "";

	time_t nowtime;
	nowtime = time(NULL);
	strftime(dateTmp, 20, "%m/%d/%Y", localtime(&nowtime));

	bankAcnt->pushback(tmp, money, cashBalance, dateTmp);

	bankAcnt->write();
}

void BankAccount::printHistory()
{
	bankAcnt->print();
}
