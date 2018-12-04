#pragma once
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
	char eventType[10];
	char stockSymbol[10];
	int share;
	double price;
	double value;
	char time[20];
	Stocklog* pPrev;
	Stocklog* pNext;
}Stocklog;

class Sort;
class StockAccount :
	public Account
{
public:
	StockAccount();
	~StockAccount();
	void read();
	void readLog();
	void write();
	void writeLog();
	void print();
	void printLog();
	void pushback(char stockSymbol[], int share);
	void pushbackLog(char eventType[], char stockSymbol[], int share, double price, double value, char time[]);
	void deleteStock(char stockSymbol[]);
	int getShare(char stockSymbol[]);
	int getLen();
	void resetShare(char stockSymbol[], int share);
	double getPrice(char stockSymbol[]);
	Stock* getHead();
	Stocklog* getLogHead();
	Stock* getTail();
	Stocklog* getLogTail();
	//the func of StockInfo
	StockInfo* readCurrentPrice();

	void displayStockPrice(char stockSymbol[]);
	void displayPortfolio();
	void buyShares();
	void sellShares();
	void displayPortfolioGraph();
	void displayTransactionHistory();

	Sort* getBubble();
	
private:
	Stock* pHead;
	StockInfo* infoHead;
	Stocklog* logHead;
	BankAccount* bankHead;
	Sort* bubble;
	Sort* insert;
	Sort* select;
};