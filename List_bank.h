#pragma once
#include"headers.h"

typedef struct Banklog
{
	char eventType[15];
	double amount;
	char date[20];
	double balance;
	Banklog* pPrev;
	Banklog* pNext;
}Banklog;

class List_bank
{
public:
	List_bank();
	~List_bank();
	void read();
	void write();
	void print();
	void pushback(char eventType[], double amount, double balance, char date[]);
	Banklog* getHead();
	Banklog* getTail();
private:
	Banklog* pHead;
};

