#pragma once
#include"headers.h"

typedef struct Stock
{
	char stockSymbol[10];
	int share;
	//char time[20];
	Stock* pPrev;
	Stock* pNext;
}Stock;

class List
{
	friend std::fstream & operator << (std::fstream &file, List &list);
public:
	List();
	~List();
	void read();
	void write();
	void print();
	void pushback(char stockSymbol[], int share);
	void insert(char stockSymbol[], int share, int position);
	void deleteStock(int position);
	int getLen();
	double getPrice(char stockSymbol[]);
	Stock* getHead();
	Stock* getTail();
	
protected:
	Stock* pHead;
};
