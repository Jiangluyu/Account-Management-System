#pragma once
#include"headers.h"

typedef struct Stock
{
	char stockSymbol[10];
	int share;
	Stock* pPrev;
	Stock* pNext;
}Stock;

typedef struct StockInfo
{
	char stockSymbol[10];
	double currentPrice;
	char date[15];
	StockInfo* pPrev;
	StockInfo* pNext;
}StockInfo;

typedef struct Stocklog
{
	char eventType[4];
	char stockSymbol[10];
	int share;
	double price;
	double value;
	char time[20];
}Stocklog;

class List_stock
{
public:
	List_stock();
	~List_stock();
	void read();
	void write();
	void print();
	void pushback(char stockSymbol[], int share);
	void insert(char stockSymbol[], int share, int position);
	void deleteStock(int position);
	//int getLen();
	double getPrice(char stockSymbol[]);
	Stock* getHead();
	Stock* getTail();

	//the func of StockInfo
	StockInfo* readCurrentPrice();
private:
	Stock* pHead;
	StockInfo* infoHead;
};
