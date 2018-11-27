#include"headers.h"

void bubbleSort::sortList(List_stock list_stock)
{
	Stock* p = new Stock;
	Stock* q = new Stock;
	for (p = list_stock.getHead()->pNext; p->pNext != NULL; p = p->pNext)
	{
		for (q = p->pNext; q->pNext != NULL; q = q->pNext)
		{
			if (p->share > q->share)
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

void selectSort::sortList(List_stock list_stock)
{
	Stock* p = new Stock;
	Stock* q = new Stock;
	Stock* minShare = new Stock;
	for (p = list_stock.getHead()->pNext; p->pNext != NULL; p = p->pNext)
	{
		minShare = p;
		for (q = p; q->pNext != NULL; q = q->pNext)
		{
			if (q->share < minShare->share)
			{
				minShare = q;
			}
		}

		int shareTemp;
		char symbolTemp[10];

		strcpy(symbolTemp, minShare->stockSymbol);
		strcpy(minShare->stockSymbol, p->stockSymbol);
		strcpy(p->stockSymbol, symbolTemp);

		shareTemp = p->share;
		p->share = minShare->share;
		minShare->share = shareTemp;
	}
}

void insertSort::sortList(List_stock list_stock)
{
	Stock* tmp = new Stock;
	Stock* p = new Stock;
	Stock* q = new Stock;

	for (p = list_stock.getHead()->pNext; p->pNext != NULL; p = p->pNext)
	{
		tmp = p;
		for (q = p; q->pNext != NULL; q = q->pNext)
		{
			if (q->share*list_stock.getPrice(q->stockSymbol) > tmp->share*list_stock.getPrice(tmp->stockSymbol))
			{
				tmp = q;
			}
		}
		int shareTmp = 0;
		char symbolTmp[10] = {};

		strcpy(symbolTmp, tmp->stockSymbol);
		strcpy(tmp->stockSymbol, p->stockSymbol);
		strcpy(p->stockSymbol, symbolTmp);

		shareTmp = tmp->share;
		tmp->share = p->share;
		p->share = shareTmp;
	}
}

