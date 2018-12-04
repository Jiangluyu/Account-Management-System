#include"headers.h"

StockAccount::StockAccount()
{
	pHead = new Stock;
	infoHead = new StockInfo;
	logHead = new Stocklog;
	bankHead = new BankAccount();
	bubble = new bubbleSort();
	insert = new insertSort();
	select = new selectSort();
}

StockAccount::~StockAccount()
{
	Stock* p = new Stock();
	Stock* q = new Stock();
	q = pHead->pNext;
	while (p != NULL)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
	delete p;

	StockInfo* r = new StockInfo();
	StockInfo* s = new StockInfo();
	s = infoHead->pNext;
	while (r != NULL)
	{
		s = r;
		r = r->pNext;
		delete s;
	}
	delete r;

	Stocklog* m = new Stocklog();
	Stocklog* n = new Stocklog();
	n = logHead->pNext;
	while (m != NULL)
	{
		n = m;
		m = m->pNext;
		delete n;
	}
	delete m;
	return;

	bankHead->~BankAccount();
}

void StockAccount::read()
{
	ifstream infile("portfolio.txt", ios::in);

	if (!infile.is_open())
	{
		cout << "Error: the file named 'portfolio.txt' does not exist" << endl;
		system("pause");
		exit(0);
	}

	//cout << "Reading portfolio from file..." << endl << endl;
	//Sleep(100);
	Stock* p = new Stock;

	p = getHead();

	while (!infile.eof())
	{
		Stock* q = new Stock;

		infile >> q->stockSymbol;
		infile >> q->share;
		//cout << q->stockSymbol << " " << q->share << "!" << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}
	
	infile.close();

	switch (bubble->getSortKind())
	{
	case 1:
		bubble->sortList(pHead);
		break;
	case 2:
		select->sortList(pHead);
		break;
	case 3:
		insert->sortList(pHead);
		break;
	}
	//cout << "finished." << endl;
}

void StockAccount::readLog()
{
	ifstream infile("Stocklog.txt", ios::in);

	if (!infile.is_open())
	{
		cout << "Error: the file named 'Stocklog.txt' does not exist" << endl;
		system("pause");
		exit(0);
	}

	//cout << "Reading log from file..." << endl << endl;
	//Sleep(100);
	Stocklog* p = new Stocklog;

	p = getLogHead();

	while (!infile.eof())
	{
		Stocklog* q = new Stocklog;

		infile >> q->eventType;
		infile >> q->stockSymbol;
		infile >> q->share;
		infile >> q->price;
		infile >> q->value;
		infile >> q->time;
		//cout << q->stockSymbol << " " << q->share << "!" << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}

	infile.close();

	//cout << "finished." << endl;
}

void StockAccount::write()
{
	ofstream outfile("portfolio.txt", ios::out);

	//cout << "Saving to portfolio..." << endl << endl;
	//Sleep(100);
	Stock* p = new Stock;

	for (p = pHead->pNext; p != NULL; p = p->pNext)
	{
		outfile << endl;
		outfile << p->stockSymbol << " " << p->share;
	}

	outfile.close();

	//cout << "finished." << endl;
}

void StockAccount::writeLog()
{
	ofstream outfile("Stocklog.txt", ios::out);

	//cout << "Saving to stocklog..." << endl << endl;
	//Sleep(100);
	Stocklog* p = new Stocklog;

	for (p = logHead->pNext; p != NULL; p = p->pNext)
	{
		outfile << endl;
		outfile << p->eventType << " " << p->stockSymbol << " " << p->share << " " << p->price << " " << p->value << " " << p->time;
	}

	outfile.close();

	//cout << "finished." << endl;
}

void StockAccount::print()
{
	Stock* tmp = new Stock;
	double totalValue = 0.0;
	cout << "Cash balance = $" << bankHead->getCashBalance() << endl;
	cout << " CompSymbol    Number    PricePerShare   TotalValue" << endl;
	for (tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext)
	{
		cout <<"    "<< setw(11) << setiosflags(ios::left) << tmp->stockSymbol << " " << setw(12) 
			<< setiosflags(ios::left) << tmp->share << " $"
			<< setw(12) << setiosflags(ios::left) << getPrice(tmp->stockSymbol) << " $" 
			<< setw(7) << setiosflags(ios::left) << tmp->share*getPrice(tmp->stockSymbol) << endl;
		totalValue += tmp->share*getPrice(tmp->stockSymbol);
	}
	cout << "Total value = $" << totalValue << endl;
}

void StockAccount::printLog()
{
	Stocklog* tmp = new Stocklog;
	cout << " Event   CompSymbol    Number      PricePerShare     TotalValue         Time" << endl;
	for (tmp = logHead->pNext; tmp != NULL; tmp = tmp->pNext)
	{
		cout << " "<<setw(9) << setiosflags(ios::left) << tmp->eventType << " " 
			<< setw(13) << setiosflags(ios::left) << tmp->stockSymbol << " " 
			<< setw(13) << setiosflags(ios::left) << tmp->share << " " 
			<< setw(15) << setiosflags(ios::left) << tmp->price << " " 
			<< setw(14) << setiosflags(ios::left) << tmp->value << " " 
			<< setw(12) << setiosflags(ios::left) << tmp->time << endl;
	}
}
//add Stock at the back of the List_stock
void StockAccount::pushback(char stockSymbol[], int share)
{
	Stock* p = new Stock;
	Stock* findNode = new Stock;      //search the Stock of which the pNext points to NULL

	strcpy(p->stockSymbol, stockSymbol);
	p->share = share;

	findNode = getTail();
	//cout << findNode->stockSymbol << findNode->share << " !" << endl;
	findNode->pNext = p;
	p->pPrev = findNode;
	p->pNext = NULL;
	switch (bubble->getSortKind())
	{
	case 1:
		bubble->sortList(pHead);
		break;
	case 2:
		select->sortList(pHead);
		break;
	case 3:
		insert->sortList(pHead);
		break;
	}
}

void StockAccount::pushbackLog(char eventType[], char stockSymbol[], int share, double price, double value, char time[])
{
	Stocklog* p = new Stocklog;
	Stocklog* findNode = new Stocklog;      //search the Stock of which the pNext points to NULL
	readLog();
	strcpy(p->eventType, eventType);
	strcpy(p->stockSymbol, stockSymbol);
	p->share = share;
	p->price = price;
	p->value = value;
	strcpy(p->time, time);

	findNode = getLogTail();
	//cout << findNode->stockSymbol << findNode->share << " !" << endl;
	findNode->pNext = p;
	p->pPrev = findNode;
	p->pNext = NULL;
}

//delete specific Stock from the List_stock
void StockAccount::deleteStock(char stockSymbol[])
{
	Stock* p = new Stock;
	Stock* findNode = new Stock;

	findNode = pHead;

	while (findNode->pNext != NULL)
	{
		if (strcmp(findNode->stockSymbol, stockSymbol) == 0)
		{
			break;
		}
		findNode = findNode->pNext;
	}

	findNode->pPrev->pNext = findNode->pNext;
	findNode->pNext->pPrev = findNode->pPrev;
	delete findNode;
	switch (bubble->getSortKind())
	{
	case 1:
		bubble->sortList(pHead);
		break;
	case 2:
		select->sortList(pHead);
		break;
	case 3:
		insert->sortList(pHead);
		break;
	}
}

int StockAccount::getShare(char stockSymbol[])
{
	read();
	Stock* findNode = new Stock;
	findNode = getHead();
	while (findNode != NULL)
	{
		if (strcmp(findNode->stockSymbol, stockSymbol) == 0)
		{
			return findNode->share;
		}
		findNode = findNode->pNext;
	}
	return 0;
}

void StockAccount::resetShare(char stockSymbol[], int share)
{
	read();
	Stock* findNode = new Stock;
	findNode = getHead();
	while (findNode != NULL)
	{
		if (strcmp(findNode->stockSymbol, stockSymbol) == 0)
		{
			findNode->share = share;
		}
		findNode = findNode->pNext;
	}
	switch (bubble->getSortKind())
	{
	case 1:
		bubble->sortList(pHead);
		break;
	case 2:
		select->sortList(pHead);
		break;
	case 3:
		insert->sortList(pHead);
		break;
	}
}

double StockAccount::getPrice(char stockSymbol[])
{
	StockInfo* findNode = new StockInfo;
	findNode = readCurrentPrice();
	for (; findNode->pNext != NULL; findNode = findNode->pNext)
	{
		if (strcmp(findNode->stockSymbol, stockSymbol) == 0)
		{
			//cout << "Price: " << findNode->currentPrice << endl;
			return findNode->currentPrice;
		}
	}

	return -1.0;
}


int StockAccount::getLen()
{
	int len = 0;
	Stock* findNode = new Stock;
	findNode = pHead;

	while (findNode->pNext != NULL)
	{
		len++;
		findNode = findNode->pNext;
	}

	return len;
}

Stock* StockAccount::getHead()
{
	return pHead;
}

Stocklog * StockAccount::getLogHead()
{
	return logHead;
}

Stock* StockAccount::getTail()
{
	Stock* p = new Stock;
	p = pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}
 
Stocklog * StockAccount::getLogTail()
{
	Stocklog* p = new Stocklog;
	p = logHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}

StockInfo* StockAccount::readCurrentPrice()
{
	srand((unsigned)time(NULL));
	string filename = {};

	if (rand() % 2 == 0)
	{
		filename = "Result_1.txt";
	}
	else
	{
		filename = "Result_2.txt";
	}
	
	ifstream infile(filename, ios::in);

	if (!infile.is_open())
	{
		cout << "Error: the file stores results does not exist" << endl;
		system("pause");
		exit(0);
	}

	StockInfo* p = new StockInfo;

	p = infoHead;

	while (!infile.eof())
	{
		StockInfo* q = new StockInfo;

		infile >> q->stockSymbol;
		infile >> q->currentPrice;
		infile >> q->date;
		//cout << q->stockSymbol << " " << q->currentPrice << " " << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}

	infile.close();

	return infoHead;
}

void StockAccount::displayStockPrice(char stockSymbol[])
{
	double price = 0.0;
	price = getPrice(stockSymbol);
	if (price < 0.0)
	{
		cout << "Not found the stock named " << stockSymbol << "." << endl;
	}
	else
	{
		cout << "Price: $" << price << endl;
	}
}

void StockAccount::displayPortfolio()
{
	read();
	print();
}

void StockAccount::buyShares()
{
	cout << "Please enter the stock symbol you wish to purchase: " << ends;

	char symbolTemp[20] = {};
	cin >> symbolTemp;
	cout << "Please enter the number of shares : " << ends;

	int shareTemp = 0;
	cin >> shareTemp;
	cout << "Please enter the maximum amount you are willing to pay per share: " << ends;

	double priceTemp = 0.0;
	cin >> priceTemp;

	double curPrice = 0.0;
	curPrice = getPrice(symbolTemp);

	if (bankHead->getCashBalance() > curPrice*shareTemp)
	{
		if (curPrice > priceTemp)
		{
			cout << "transaction failed : for the price of " << symbolTemp
				<< " is $" << curPrice << " , which is larger than the price you can accept." << endl;
			return;
		}
		else if (curPrice == -1)
		{
			cout << "transaction failed : for the stock named " << symbolTemp
				<< " does not exist." << endl;
			return;
		}
		else
		{
			cout << "You have purchased " << shareTemp << "shares of " << symbolTemp
				<< " at $" << curPrice << " each for a total of $" << shareTemp * curPrice << "." << endl;
			//add & write to the banklog
			bankHead->withdrawMoney(shareTemp*curPrice);

			if (getShare(symbolTemp) == 0)
			{
				pushback(symbolTemp, shareTemp);
			}
			else
			{
				resetShare(symbolTemp, getShare(symbolTemp) + shareTemp);
			}
			//write to the portfolio
			write();

			char eventType[10] = "Buy";
			time_t now;
			struct tm *tm_now;
			char timeTmp[20];
			time(&now);
			tm_now = localtime(&now);
			strftime(timeTmp, 20, "%H:%M:%S", localtime(&now));

			pushbackLog(eventType, symbolTemp, shareTemp, getPrice(symbolTemp), shareTemp*getPrice(symbolTemp), timeTmp);
			writeLog();

			return;
		}
	}
	else
	{
		cout << "transaction failed: for you cannot afford for it." << endl;
		return;
	}
	
}

void StockAccount::sellShares()
{
	cout << "Please enter the stock symbol you wish to sell: " << ends;

	char symbolTemp[20];
	cin >> symbolTemp;
	cout << "Please enter the number of shares : " << ends;

	int shareTemp;
	cin >> shareTemp;
	cout << "Please enter the minimum price you are willing to sell per share: " << ends;

	double priceTemp;
	cin >> priceTemp;

	double curPrice = 0.0;
	curPrice = getPrice(symbolTemp);
	if (curPrice < priceTemp)
	{
		cout << "transaction failed : for the price of " << symbolTemp
			<< " is $" << curPrice << " , which is lower than the price you can accept." << endl;
		return;
	}
	else
	{
		if (getShare(symbolTemp) >= shareTemp)
		{
			cout << "You have sold " << shareTemp << "shares of " << symbolTemp
						<< " at $" << curPrice << " each for a total of " << shareTemp * curPrice << "." << endl;
			bankHead->depositMoney(shareTemp*curPrice);

			if (getShare(symbolTemp) == shareTemp)
			{
				deleteStock(symbolTemp);
			}
			else
			{
				resetShare(symbolTemp, getShare(symbolTemp) - shareTemp);
			}
			write();

			char eventType[10] = "Sell";
			time_t now;
			struct tm *tm_now;
			char timeTmp[20];
			time(&now);
			tm_now = localtime(&now);
			strftime(timeTmp, 20, "%H:%M:%S", localtime(&now));

			pushbackLog(eventType, symbolTemp, shareTemp, getPrice(symbolTemp), shareTemp*getPrice(symbolTemp), timeTmp);
			writeLog();
			return;
		}
		else
		{
			cout << "transaction failed : for the share of " << symbolTemp
				<< " you owned is " << getShare(symbolTemp) << " , which is less than the share you can sell." << endl;
			return;
		}
	}
}

void StockAccount::displayPortfolioGraph()
{
	//MATLAB
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "Error: Not Found"<< endl;
		exit(1);
	}

	int len = getLen();
	int vecShare[100];
	string vecSymbol[100];
	Stock* findNode = new Stock;
	findNode = pHead->pNext;
	for (int i = 0; i < len; i++)
	{
		vecShare[i] = findNode->share;
		vecSymbol[i] = findNode->stockSymbol;
		findNode = findNode->pNext;
	}

	// generate variables

	mxArray *T = NULL;
	T = mxCreateDoubleMatrix(1, len, mxREAL);
	memcpy((void *)mxGetPr(T), (void *)vecShare, len * sizeof(vecShare[0]));

	engPutVariable(ep, "T", T);         // put data to engine

	mxArray *Y = NULL;
	Y = mxCreateDoubleMatrix(1, len, mxREAL);
	memcpy((void *)mxGetPr(Y), (void *)vecSymbol, sizeof(vecSymbol));

	engPutVariable(ep, "Y", Y);         // put data to engine

	// execute matlab operations
	//engEvalString(ep, "Y=T;");
	engEvalString(ep, "plot(T,Y);");
	engEvalString(ep, "title('Portfolio');");
	engEvalString(ep, "xlabel('StockSymbol');");
	engEvalString(ep, "ylabel('Share');");

	system("pause");

	// clean operation(don't forget!!!)
	mxDestroyArray(T);
	engEvalString(ep, "close;");

	// close engine
	engClose(ep);
}

void StockAccount::displayTransactionHistory()
{
	readLog();
	printLog();
}

Sort * StockAccount::getBubble()
{
	return bubble;
}

