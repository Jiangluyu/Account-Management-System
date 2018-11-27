#include"headers.h"

int main(void)
{
	StockAccount *stock = new StockAccount();
	/*
	stock->read();
	stock->print();
	system("pause");
	char symbol[] = "LOUIS";
	stock->pushback(symbol, 200);
	stock->print();
	system("pause");
	stock->write();
	system("pause");
	//test list_stock
	*/

	stock->readCurrentPrice();
	system("pause");
}