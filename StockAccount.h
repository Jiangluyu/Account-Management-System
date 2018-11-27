#pragma once
#include"headers.h"

class StockAccount :
	public Account
{
public:
	StockAccount();
	void displayStockPrice(char stockSymbol[]);
	void displayPortfolio();
	void buyShares();
	void sellShares();
	void displayPortfolioGraph();
	void displayTransactionHistory();
	List_bank* getBankAccount();
private:
	List_stock stockAcnt;
};

