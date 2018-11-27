#include "headers.h"

List_bank::List_bank()
{
	pHead = new Banklog();
}

List_bank::~List_bank()
{
	Banklog* p = new Banklog();
	Banklog* q = new Banklog();
	q = pHead->pNext;
	while (p != NULL)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
	delete p;
}

void List_bank::read()
{
	ifstream infile("Banklog.txt", ios::in);

	if (!infile.is_open())
	{
		cout << "Error: the file named 'Banklog.txt' does not exist" << endl;
		system("pause");
		exit(0);
	}

	cout << "Reading from file..." << endl << endl;
	Sleep(100);
	Banklog* p = new Banklog();

	p = pHead;

	while (!infile.eof())
	{
		Banklog* q = new Banklog();

		infile >> q->eventType;
		infile >> q->amount;
		infile >> q->balance;
		infile >> q->date;
		//cout << q->stockSymbol << " " << q->share << "!" << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}

	infile.close();

	cout << "finished." << endl;
}

void List_bank::write()
{
	ofstream outfile("Banklog.txt", ios::out);

	cout << "Saving to file..." << endl << endl;
	Sleep(100);
	Banklog* p = new Banklog();

	for (p = pHead->pNext; p->pNext != NULL; p = p->pNext)
	{
		outfile << p->eventType << " " << p->amount << " " << p->balance << " " << p->date << endl;
	}

	outfile.close();

	cout << "finished." << endl;
}

void List_bank::print()
{
	Banklog* tmp = new Banklog();
	for (tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext)
	{
		cout << "eventType: " << tmp->eventType << " " << "amount: " << tmp->amount << " " << "balance: " << tmp->balance << " " << "date: " << tmp->date << endl;
	}
}

void List_bank::pushback(char eventType[], double amount, double balance, char date[])
{
	Banklog* p = new Banklog();
	Banklog* findNode = new Banklog();      //search the Stock of which the pNext points to NULL

	strcpy(p->eventType, eventType);
	p->amount = amount;
	p->balance = balance;
	strcpy(p->date, date);

	findNode = getTail();
	//cout << findNode->stockSymbol << findNode->share << " !" << endl;
	findNode->pNext = p;
	p->pPrev = findNode;
	p->pNext = NULL;
}

Banklog * List_bank::getHead()
{
	return pHead;
}

Banklog * List_bank::getTail()
{
	Banklog* p = new Banklog();
	p = pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}
