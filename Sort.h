#pragma once
#include"StockAccount.h"
//here use the Strategy 
class StockAccount;
class Sort
{
public:
	Sort();
	virtual void sortList(Stock* list_stock) = 0;
	int getSortKind();
	void setsortKind(int setSortKind);
	double getPrice(char stockSymbol[]);
	StockInfo* readCurrentPrice();
	//void insert(Stock* list_stock, char stockSymbol[], int share, int position);
protected:
	int sortKind;
	StockInfo* infoHead;
};

class bubbleSort :public Sort
{
public:
	void sortList(Stock* list_stock);
};

class selectSort :public Sort
{
public:
	void sortList(Stock* list_stock);
};

class insertSort :public Sort
{
public:
	void sortList(Stock* list_stock);
};