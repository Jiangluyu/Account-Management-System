#include"headers.h"

StockAccount::StockAccount()
{
}

void StockAccount::displayStockPrice(char stockSymbol[])
{
	double price = 0.0;
	price = stockAcnt.getPrice(stockSymbol);
	if (price < 0.0)
	{
		cout << "Not found the stock named " << stockSymbol << "." << endl;
	}
	else
	{
		cout << "Price: " << price << endl;
	}
}

void StockAccount::displayPortfolio()
{
	stockAcnt.print();
}

void StockAccount::buyShares()
{
	
}

void StockAccount::sellShares()
{
}

void StockAccount::displayPortfolioGraph()
{
}

void StockAccount::displayTransactionHistory()
{
}

List_bank * StockAccount::getBankAccount()
{
	return bankAcnt;
}
