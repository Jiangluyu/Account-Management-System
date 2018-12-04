#include"headers.h"

BankAccount::BankAccount()
{
	cashBalance = 0.0;
	bankLogHead = new Banklog;
}

BankAccount::~BankAccount()
{
	Banklog* p = new Banklog();
	Banklog* q = new Banklog();
	q = bankLogHead->pNext;
	while (p != NULL)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
	delete p;
}

void BankAccount::read()
{
	ifstream infile("Banklog.txt", ios::in);

	if (!infile.is_open())
	{
		cout << "Error: the file named 'Banklog.txt' does not exist" << endl;
		system("pause");
		exit(0);
	}

	//cout << "Reading banklog from file..." << endl << endl;
	//Sleep(100);
	Banklog* p = new Banklog;

	p = getHead();

	while (!infile.eof())
	{
		Banklog* q = new Banklog;

		infile >> q->eventType;
		infile >> q->amount;
		infile >> q->date;
		infile >> q->balance;

		//cout << q->eventType << " " << q->amount << " " << q->balance << " " << q->date << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}
	
	infile.close();

	//cout << "finished." << endl;
}

void BankAccount::write()
{
	ofstream outfile("Banklog.txt", ios::out);

	//cout << "Saving to banklog..." << endl << endl;
	//Sleep(100);
	Banklog* p = new Banklog;

	for (p = bankLogHead->pNext; p != NULL; p = p->pNext)
	{
		outfile << endl;
		outfile << p->eventType << " " << p->amount << " " << p->date << " " << p->balance;
	}

	outfile.close();

	//cout << "finished." << endl;
}

void BankAccount::print()
{
	Banklog* tmp = new Banklog;
	cout << " Event       Amount        Date        Balance" << endl;
	for (tmp = bankLogHead->pNext; tmp != NULL; tmp = tmp->pNext)
	{
		cout << setw(12) << setiosflags(ios::left) << tmp->eventType << " $" << setw(8) << setiosflags(ios::left)
			<< tmp->amount << " " << setw(15) << setiosflags(ios::left) << tmp->date << " $" << setw(10)
			<< setiosflags(ios::left) << tmp->balance << endl;
	}
}

void BankAccount::pushback(char eventType[], double amount, char date[], double balance)
{
	Banklog* p = new Banklog;
	Banklog* findNode = new Banklog;      //search the Stock of which the pNext points to NULL

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

Banklog * BankAccount::getHead()
{
	return bankLogHead;
}

Banklog * BankAccount::getTail()
{
	Banklog* p = new Banklog;
	p = bankLogHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}

double BankAccount::getCashBalance()
{
	read();
	cashBalance = getTail()->balance;
	return cashBalance;
}

void BankAccount::displayAccountBalance()
{
	cout << "You have $" << getCashBalance() << " in your bank account." << endl;
}

void BankAccount::depositMoney(double money)
{
	cashBalance = getCashBalance();
	cashBalance += money;

	char tmp[15] = "Deposit";
	char dateTmp[20] = "";
	Banklog* p = new Banklog;

	time_t nowtime;
	nowtime = time(NULL); 
	strftime(dateTmp, 20, "%m/%d/%Y", localtime(&nowtime));

	pushback(tmp, money, dateTmp, cashBalance);
	//cout << "?" << endl;
	write();
}

void BankAccount::withdrawMoney(double money)
{
	cashBalance = getCashBalance();
	cashBalance -= money;

	char tmp[15] = "Withdrawal";
	char dateTmp[20] = "";

	time_t nowtime;
	nowtime = time(NULL);
	strftime(dateTmp, 20, "%m/%d/%Y", localtime(&nowtime));

	pushback(tmp, money, dateTmp, cashBalance);

	write();
}

void BankAccount::printHistory()
{
	read();
	print();
}
