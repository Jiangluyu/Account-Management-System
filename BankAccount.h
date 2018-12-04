#pragma once
typedef struct Banklog
{
	char eventType[15];
	double amount;
	char date[20];
	double balance;
	Banklog* pPrev;
	Banklog* pNext;
}Banklog;

class BankAccount :
	public Account
{
public:
	BankAccount();
	~BankAccount();

	void read();
	void write();
	void print();
	void pushback(char eventType[], double amount, char date[], double balance);
	Banklog* getHead();
	Banklog* getTail();

	double getCashBalance();
	void displayAccountBalance();
	void depositMoney(double money);
	void withdrawMoney(double money);
	void printHistory();
private:
	Banklog* bankLogHead;
};

