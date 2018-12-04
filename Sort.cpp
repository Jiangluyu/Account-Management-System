#include"headers.h"

Sort::Sort()
{
	sortKind = 3;
	infoHead = new StockInfo;
}

void bubbleSort::sortList(Stock* list_stock)
{
	Stock* p = new Stock;
	Stock* q = new Stock;
	for (p = list_stock->pNext; p != NULL; p = p->pNext)
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->share*getPrice(p->stockSymbol) <= q->share*getPrice(q->stockSymbol))
			{
				int shareTemp;
				char symbolTemp[10];

				strcpy(symbolTemp, p->stockSymbol);
				strcpy(p->stockSymbol, q->stockSymbol);
				strcpy(q->stockSymbol, symbolTemp);

				shareTemp = p->share;
				p->share = q->share;
				q->share = shareTemp;
			}
		}
	}
}

void selectSort::sortList(Stock* list_stock)
{
	Stock* p = new Stock;
	Stock* q = new Stock;
	Stock* maxShare = new Stock;
	for (p = list_stock->pNext; p != NULL; p = p->pNext)
	{
		maxShare = p;
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			if (q->share*getPrice(q->stockSymbol) > maxShare->share*getPrice(maxShare->stockSymbol))
			{
				maxShare = q;
			}
		}

		int shareTemp;
		char symbolTemp[10];

		strcpy(symbolTemp, maxShare->stockSymbol);
		strcpy(maxShare->stockSymbol, p->stockSymbol);
		strcpy(p->stockSymbol, symbolTemp);

		shareTemp = p->share;
		p->share = maxShare->share;
		maxShare->share = shareTemp;
	}
}

void insertSort::sortList(Stock* list_stock)
{
	Stock* p = new Stock;
	Stock* q = new Stock;
	if (list_stock->pNext->pNext == NULL || list_stock->pNext == NULL)
	{
		return;
	}

	for (p = list_stock->pNext->pNext; p != NULL; p = p->pNext)
	{
		Stock* tmp = new Stock;
		for (q = list_stock->pNext; q != p; q = q->pNext)
		{
			if (q->share*getPrice(q->stockSymbol) < p->share*getPrice(p->stockSymbol))
			{
				if(p->pNext != NULL)
				{
					tmp = p->pPrev;
					p->pPrev->pNext = p->pNext;
					p->pNext->pPrev = p->pPrev;

					q->pPrev->pNext = p;
					p->pPrev = q->pPrev;
					q->pPrev = p;
					p->pNext = q;
					p = tmp;
					break;
				}
				else
				{
					tmp = p->pPrev;
					p->pPrev->pNext = NULL;
					
					q->pPrev->pNext = p;
					p->pPrev = q->pPrev;
					q->pPrev = p;
					p->pNext = q;
					p = tmp;
					break;
				}
			}
		}
	}
}

int Sort::getSortKind()
{
	return sortKind;
}

void Sort::setsortKind(int setSortKind)
{
	sortKind = setSortKind;
}

double Sort::getPrice(char stockSymbol[])
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


StockInfo* Sort::readCurrentPrice()
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

/*
//insert Stock at the specific position
void Sort::insert(Stock* list_stock, char stockSymbol[], int share, int position)
{
	Stock* p = new Stock;
	Stock* findNode = new Stock;

	strcpy(p->stockSymbol, stockSymbol);
	p->share = share;

	findNode = list_stock;

	for (int i = 0; i < position; i++)
	{
		if (findNode->pNext != NULL)
		{
			findNode = findNode->pNext;
		}
	}

	p->pNext = findNode->pNext;
	findNode->pNext->pPrev = p;
	findNode->pNext = p;
	p->pPrev = findNode;
}
*/

