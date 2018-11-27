#include "headers.h"

List_stock::List_stock()
{
	pHead = new Stock();
	infoHead = new StockInfo();
}

List_stock::~List_stock()
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
}

void List_stock::read()
{
	ifstream infile("portfolio.txt", ios::in);
	
	if (!infile.is_open())
	{
		cout << "Error: the file named 'portfolio.txt' does not exist" << endl;
		system("pause");	
		exit(0);
	}

	cout << "Reading from file..." << endl << endl;
	Sleep(100);
	Stock* p = new Stock();

	p = pHead;

	while (!infile.eof())
	{
		Stock* q = new Stock();
		
		infile >> q->stockSymbol;
		infile >> q->share;
		//cout << q->stockSymbol << " " << q->share << "!" << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}

	infile.close();
	
	cout << "finished." << endl;
}

void List_stock::write()
{
	ofstream outfile("portfolio.txt", ios::out);

	cout << "Saving to file..." << endl << endl;
	Sleep(100);
	Stock* p = new Stock();

	for (p = pHead->pNext; p->pNext != NULL; p = p->pNext)
	{
		outfile << p->stockSymbol << " " << p->share << endl;
	}

	outfile.close();

	cout << "finished." << endl;
}

void List_stock::print()
{
	Stock* tmp = new Stock();
	for (tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext)
	{
		cout << "stock symbol: " << tmp->stockSymbol << " " << "share: " << tmp->share << endl;
	}
}

//add Stock at the back of the List_stock
void List_stock::pushback(char stockSymbol[], int share)
{
	Stock* p = new Stock();
	Stock* findNode = new Stock();      //search the Stock of which the pNext points to NULL

	strcpy(p->stockSymbol, stockSymbol);
	p->share = share;
	
	findNode = getTail();
	//cout << findNode->stockSymbol << findNode->share << " !" << endl;
	findNode->pNext = p;
	p->pPrev = findNode;
	p->pNext = NULL;
}

//insert Stock at the apecific position
void List_stock::insert(char stockSymbol[], int share, int position)
{
	Stock* p = new Stock();
	Stock* findNode = new Stock();

	strcpy(p->stockSymbol, stockSymbol);
	p->share = share;

	findNode = pHead;

	for (int i = 0; i < position; i++)
	{
		if (findNode->pNext != NULL)
		{
			findNode = findNode->pNext;
		}
		else
		{
			cout << "Invalid visit" << std::endl;
		}
	}

	p->pNext = findNode->pNext;
	findNode->pNext->pPrev = p;
	findNode->pNext = p;
	p->pPrev = findNode;
}

//delete specific Stock from the List_stock
void List_stock::deleteStock(int position)
{
	Stock* p = new Stock();
	Stock* findNode = new Stock();

	findNode = pHead;

	for (int i = 0; i < position; i++)
	{
		if (findNode->pNext != NULL)
		{
			findNode = findNode->pNext;
		}
		else
		{
			std::cout << "Invalid visit" << std::endl;
		}
	}

	findNode->pPrev->pNext = findNode->pNext;
	findNode->pNext->pPrev = findNode->pPrev;
	delete findNode;
}
double List_stock::getPrice(char stockSymbol[])
{
	StockInfo* findNode = new StockInfo();
	findNode = readCurrentPrice();
	for (; findNode->pNext != NULL; findNode = findNode->pNext)
	{
		if (strcpy(findNode->stockSymbol, stockSymbol))
		{
			//cout << "Price: " << findNode->currentPrice << endl;
			return findNode->currentPrice;
		}
	}

	return -1.0;
}
/*
int List_stock::getLen()
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
}*/

Stock* List_stock::getHead()
{
	return pHead;
}

Stock* List_stock::getTail()
{
	Stock* p = new Stock();
	p = pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}

StockInfo* List_stock::readCurrentPrice()
{
	ifstream infile("Result_1.txt", ios::in);

	if (!infile.is_open())
	{
		cout << "Error: the file stores results does not exist" << endl;
		system("pause");
		exit(0);
	}

	StockInfo* p = new StockInfo();

	p = infoHead;

	while (!infile.eof())
	{
		StockInfo* q = new StockInfo();

		infile >> q->stockSymbol;
		infile >> q->currentPrice;
		infile >> q->date;
		cout << q->stockSymbol << " " << q->currentPrice << " " << q->date << "!" << endl;
		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}

	infile.close();

	return infoHead;
}

