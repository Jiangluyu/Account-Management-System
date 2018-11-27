#include "headers.h"

List::List()
{
	pHead = new Stock;
}

List::~List()
{
	Stock* p = new Stock;
	Stock* q = new Stock;
	q = pHead->pNext;
	while (p != NULL)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
	delete p;
}

void List::read()
{
	ifstream infile("portfolio.txt", ios::in | ios::binary);
	string readfile;
	
	if (!infile.is_open())
	{
		cout << "Error: the file named 'portfolio.txt' does not exist" << endl;
		system("pause");
		exit(0);
	}

	cout << "Reading from file..." << endl;
	
	Stock* p = new Stock();

	p = pHead;

	while (!infile.eof())
	{
		Stock* q = new Stock;
		//char ignoreTmp[20];
		infile >> q->stockSymbol >> q->share;

		q->pNext = NULL;
		p->pNext = q;
		q->pPrev = p;
		p = q;
	}

	cout << "finished." << endl;
	print();
	system("pause");
}

void List::write()
{
}

void List::print()
{
	Stock* tmp = new Stock;
	for (tmp = pHead->pNext; tmp->pNext != NULL; tmp = tmp->pNext)
	{
		cout << "stock symbol: " << tmp->stockSymbol << " " << "share: " << tmp->share << endl;
	}
}

//add Stock at the back of the list
void List::pushback(char stockSymbol[], int share)
{
	Stock* p = new Stock;
	Stock* findNode = new Stock;      //search the Stock of which the pNext points to NULL

	strcpy(p->stockSymbol, stockSymbol);
	p->share = share;
	
	findNode = pHead;

	while (findNode->pNext != NULL)
	{
		findNode = findNode->pNext;
	}

	findNode->pNext = p;
	p->pPrev = findNode;
	p->pNext = NULL;
}

//insert Stock at the apecific position
void List::insert(char stockSymbol[], int share, int position)
{
	Stock* p = new Stock;
	Stock* findNode = new Stock;

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
			std::cout << "Invalid visit" << std::endl;
		}
	}

	p->pNext = findNode->pNext;
	findNode->pNext->pPrev = p;
	findNode->pNext = p;
	p->pPrev = findNode;
}

//delete specific Stock from the list
void List::deleteStock(int position)
{
	Stock* p = new Stock;
	Stock* findNode = new Stock;

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

int List::getLen()
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

double List::getPrice(char stockSymbol[])
{
	return 0.0;
}

Stock* List::getHead()
{
	return pHead;
}

Stock* List::getTail()
{
	Stock* p = new Stock;
	p = pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}

std::fstream & operator<<(std::fstream & file, List & list)
{
	{
		Stock* findNode = list.getHead();
		int len = list.getLen();
		for (int i = 0; i < len; i++)
		{
			file << findNode->stockSymbol << " " << findNode->share << " ";//<< getTime();
			findNode = findNode->pNext;
		}
		return file;
	}
}
